#include "../pmj.h"

void pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
			WCOREDUMP(status) ? " (core file generated)" : "");
#else
			"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
int main(void)
{
	pid_t pid;
	int status, zero = 0;
	
	if ((pid = fork()) < 0)
		err_quit("fork error");
	else if (pid == 0) /* child */
		exit(7);
	
	if (wait(&status) != pid) /* wait for child */
		err_quit("wait error");
	pr_exit(status); 	/* and print its status */
	
	if ((pid = fork()) < 0)
		err_quit("fork error");
	else if (pid == 0) 	/* child */
		abort(); 		/* generates SIGABRT */
	
	if (wait(&status) != pid) 	/* wait for child */
		err_quit("wait error");
	pr_exit(status); 			/* and print its status */

	if ((pid = fork()) < 0)
		err_quit("fork error");
	else if (pid == 0) /* child */
		status /= zero; /* divide by 0 generates SIGFPE */

	if (wait(&status) != pid) /* wait for child */
		err_quit("wait error");
	pr_exit(status); /* and print its status */
	
	exit(0);	
}


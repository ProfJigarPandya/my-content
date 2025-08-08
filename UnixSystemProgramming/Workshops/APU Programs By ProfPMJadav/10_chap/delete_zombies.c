#include "../pmj.h"

sigjmp_buf env;
int main()
{
    pid_t pid;
    int n = 20;
    struct sigaction sa;
    void delete_zombies(int);

    sigfillset(&sa.sa_mask);
    sa.sa_handler = delete_zombies;
    sa.sa_flags = 0;
    sigaction(SIGCHLD, &sa, NULL);

    sigsetjmp(env, 1);
    if ((pid = fork()) < 0)
		err_quit("fork() error");

    if (pid > 0)   /***** Parent *****/
    {
         printf("Created child %d\n", pid);
         sleep(n -= 2);
         kill(0, SIGKILL);
    }
    else           /***** Child  *****/
    {
         sleep(2);
         exit(0);   /******  Not necessary here but...  ******/
    }
	exit(0);
}
void delete_zombies(int signo)
{
    pid_t kidpid;
    int status;

    printf("Inside zombie deleter:  ");
    while ((kidpid = waitpid(-1, &status, WNOHANG)) > 0)
    {
         printf("Signal %d, Child %d terminated with status %d\n", signo, kidpid, status);
    }
    siglongjmp(env,1);
}



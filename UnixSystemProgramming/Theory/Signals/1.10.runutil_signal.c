#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define MAXLINE 4096

extern int errno;
static void sig_int(int); /* our signal-catching function */

int main(void)
{
	char buf[MAXLINE]; /* from apue.h */
	pid_t pid;
	int status;
	if (signal(SIGCHLD, sig_int) == SIG_ERR)
		printf("signal error: %s",strerror(errno));
	if (signal(SIGINT, sig_int) == SIG_ERR)
		printf("signal error: %s",strerror(errno));

	printf(" Welcome %% "); /* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) 
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; /* replace newline with null */
		if ((pid = fork()) < 0) 
		{
			printf("fork error %s",strerror(errno));
		} 
		else if (pid == 0) 
		{ /* child */
			char buffer[100];
			sprintf(buffer,"\n Child: process id %d ",getpid());
			write(STDOUT_FILENO,buffer,strlen(buffer));
			//printf("\n Child: process id %d \n",getpid());
			//printf("\n Child: process id %d ",getpid());
			execlp(buf, buf, (char *)0);
			printf("couldn't execute: %s. Error %s", buf,strerror(errno));
			exit(127);
		}
		/* parent */
		printf("\n Parent: process id %d \n",getpid());
		printf("\n Shell: process id %d \n",getppid());
		if ((pid = waitpid(pid, &status, 0)) < 0)
			printf("waitpid error : %s",strerror(errno));
	
		printf("%% ");
	}
	exit(0);
}

void sig_int(int signo)
{
	printf("interrupt pid %d, signo %d \n%%",getpid(),signo);
}

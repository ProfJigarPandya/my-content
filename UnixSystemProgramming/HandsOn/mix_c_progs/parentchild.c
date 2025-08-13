//To demonstrate SIGCHLD signal.
//Theory says by default SIGCHLD is set to be ignored by parent and generated when child terminates.
//ps -ax -o pid,ppid,cmd | grep systemd
//From another terminal kill <childprocessid> while program is running to see that the SIGCHLD is handled by parent. May practice kill -s <signalcode> <processid> too.

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


void sigchildHandler(int signo);

int main()
{
	int forkResponse;
	printf("\n Its me parent, just started and my process id %d ", getpid());
	
	if(signal(SIGCHLD,sigchildHandler)==SIG_ERR)
	{
		printf("\n Error in handling SIGCHLD ");
		exit(1);
	}	

	printf("\n Press any key to fork a child ");
	getchar();

	if((forkResponse = fork()) <0 )
	{
		printf("\n Error during fork. ");
		exit(1);
	}
	
	if(forkResponse==0)//Child process
	{
		int i=0;
		while(1)
		{
			printf("\n I am child process and my process id %d with parent process id %d iteration %d",getpid(),getppid(), ++i);
		}
	}
	
	//parent contines further
	while(1);

	
}
void sigchildHandler(int signo)
{
	printf("\n child terminated or stopped");
}

/*
 Demo zombie process. A child is not reaped by its parent then the child process remains to be zombie.
 ps -al | grep demozombie
 exercise 8.6
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid;
	int status;
	char comm[256];
	printf("\nHi from main. PID %d, PPID %d \n", getpid(), getppid());
	printf("\nPress any key to fork a child now \n");
	getchar();
	if((pid=fork())<0)
	{
		printf("\n Fork failed \n");
		exit(EXIT_FAILURE);	
	}
	else if(pid == 0)//child
	{
		printf("\nHi from child. PID %d, PPID %d \n", getpid(), getppid());
		close(0);//close stdin
		
		printf("\nPress any key to finish the child \n");
		getchar();
		
		printf("\n Child finished \n");
		return(0);
	}
	else//parent
	{
		printf("\nHi from parent. PID %d, PPID %d \n", getpid(), getppid());
		sprintf(comm,"ps -lp %d",pid);
		system(comm);
		printf("\nPress any key to reap the child process \n");
		getchar();
		waitpid(pid,&status,WNOHANG);
		printf("\n child reaped successfully with status %d \n",status);
		sprintf(comm,"ps -lp %d",pid);
		system(comm);
		printf("\n Press any key to finish the parent \n");
		getchar();	
	}
	
	
}

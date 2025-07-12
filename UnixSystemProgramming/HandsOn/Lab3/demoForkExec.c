/*  
 * Write a C program to create a new process and run another program in it.
 * (Use of fork, wait, exec system calls) and to display process information of all the processes existing in the system (Understand /proc file system)*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	
	pid_t id;		
	int status;
 	char *const argv[]={"Network","Java","Portable",NULL};

	id=fork();//On success, the PID of the child process is returned in the parent, and 0 is returned in the child.  On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.


	if(id==0) //child process
	{
		printf("\nChild  : My id is %d.\nChild  : My parent id is %d",getpid(),getppid());
		printf("\nChild  : Running calculator now");
		execvp("./myapp.o",argv);
		printf("\nChild  : Terminating now.");
	}
	else //parent process
	{
		printf("\nParent : My id is %d.\nParent : My child process is running with id %d",getpid(),id);
		waitpid(id,&status,0);
		printf("\nParent : Status collected from child -  %d ",status);
		printf("\nParent : Terminating now.");
	}
	

	return (EXIT_SUCCESS);
}


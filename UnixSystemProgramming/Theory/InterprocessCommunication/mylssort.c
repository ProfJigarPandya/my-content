/* To demonstrate interprocess (parent and child) communication, 
The program creates a pipe and after let parent run ls and write output to pipe while child reads from pipe as standard input for command sort and runs sort finally displays output on the screen.

Same output as running below command directly
ls | sort


man 2 pipe
man 3 perror
man 3 exit
man 2 fork
man 2 dup
man 3 stdin
man 3 exec
man fflush



On  program  startup,  the  integer file descriptors associated with the streams stdin,stdout,  and  stderr  are  0,  1,  and  2,  respectively.   The  preprocessor   symbols
STDIN_FILENO,  STDOUT_FILENO,  and  STDERR_FILENO  are  defined  with  these  values in<unistd.h>. 


*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

extern int errno;
extern char **environ;

int main(int argc, char *argv[])
{
	int pipefd[2];
	int status;
	//printf("\n To demo ipc using pipe ");
	status = pipe(pipefd);	
	if(status!=0)
	{
		perror("Creating pipe failed ... ");
		exit(EXIT_FAILURE);
	}
	
	//printf("\n Pipe created successfully Read end fd value %d, write end fd value %d",pipefd[0],pipefd[1]);
	

	int fork_returned;
	if((fork_returned=fork())==-1)
	{
		perror("\nFork API failed ...");
		exit(EXIT_FAILURE);
	}
	
	if(fork_returned!=0)//Parent process
	{
		int dup_returned;
		//printf("\n Parent process here ...%u",getpid());
		close(pipefd[0]); //Close read end of pipe
		fflush(stdout);
		close(STDOUT_FILENO);//1
		if((dup_returned=dup(pipefd[1]))==-1)
		{
			perror("\nParent DUP failed");
			exit(EXIT_FAILURE);
		}
		//printf("\n Parent DUP returned FD %d ",dup_returned);//expected 1 as we just have closed stdout the lowest . !!! This actually gets written to pipe write end !!!
		if(execlp("ls","ls",(char *)0)==-1)//Only if exec error
		{
			//printf("\n Exec ls failed ");
			perror("\n exec ls from parent failed ...");
			exit(EXIT_FAILURE);
		}
		//printf("\n Parent will never be here if exec ls succeeded...");
	}
	else//Child process
	{
		int dup_returned;
		//printf("\n Child process here ...%u (parent %u)",getpid(),getppid());
		close(pipefd[1]); //Close write end of pipe
		close(STDIN_FILENO);//0
		if((dup_returned=dup(pipefd[0]))==-1)
		{
			perror("\nChild DUP failed");
			exit(EXIT_FAILURE);
		}
		//printf("\n Child DUP returned FD %d ",dup_returned);//expected 0 as we just have closed stdin the lowest

		if(execlp("sort","sort",(char *) 0)==-1)//Only if exec error
		{
			printf("\n Exec sort failed ");
			perror("\n exec sort from child failed ...");
			exit(EXIT_FAILURE);
		}
		printf("\n Child will never be here if exec sort succeeded ...");
	}
	
	return(0);
}

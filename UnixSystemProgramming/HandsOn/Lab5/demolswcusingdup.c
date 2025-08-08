/*
 * Write a C program that can understand the redirection and pipe features similar to shell.
 * (Use of dup system call)
   gcc -Wall demolswcusingdup.c -o demolswcusingdup.o
   ./demolswcusingdup.o "ls|wc" 
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLENCOMM 50

extern int errno;
int main(int argc, char *argv[])
{
	
	int i;
	char leftcomm[MAXLENCOMM],rightcomm[MAXLENCOMM],*ptrpipe;
	int pipefd[2];
	int lchildpid, rchildpid, status;
	int dupfdl, dupfdr;
	if(argc!=2)
	{
		printf("\n Usage: %s %s (Command options not supported)",argv[0],"command1|command2");
		exit(1);
	}
	for(i=0;i<argc;i++)
		printf("\n %d %s ",i,argv[i]);
	
	//extract commands
	ptrpipe=strstr(argv[1],"|");
	*ptrpipe='\0';
	printf("\n%s | %s\n",strcpy(leftcomm,argv[1]),strcpy(rightcomm,ptrpipe+1));
	
	//create a pipe
	if(pipe(pipefd)==-1)
	{
		printf("\n Pipe creation failed: %s \n",strerror(errno));
		exit(1);
	}
	else
	{
		printf("\n Pipe read fd %d and write fd %d \n",pipefd[0],pipefd[1]);
	}
	
	printf("\n Press enter to fork for left comm \n");
	getchar();
	//create child for left comm
	if( (lchildpid=fork()) ==0)
	{
		close(pipefd[0]);//close pipe read end as left comm need to write to pipe only.
	
		close(1); //close stdout of left comm as it needs to flow to pipe write end
		dupfdl=dup(pipefd[1]);
		if(dupfdl==-1)
		{
			printf("\n dup failed left: %s \n",strerror(errno));
			exit(1); 
		}
		else
		{
			//printf("\n dup left %d \n",dupfdl);
		}
		execlp(leftcomm,leftcomm,NULL);
		exit(0);
	}
	else if(lchildpid==-1)
	{
		printf("\n left comm child fork failed ");
		exit(1);
	} 

	printf("\n Press enter to fork for right comm \n");
	getchar();
	//create child for right comm
	if( (rchildpid=fork()) ==0)
	{
		close(pipefd[1]);//close pipe write end as right comm need to read from pipe only.
	
		close(0); //close stdin of right comm as it needs to flow from pipe read end
		dupfdr=dup(pipefd[0]);
		if(dupfdr==-1)
		{
			printf("\n dup failed right: %s \n",strerror(errno));
			exit(1); 
		}
		else
		{
			//printf("\n dup right %d \n",dupfdr);
		}
		
		execlp(rightcomm,rightcomm,NULL);
		exit(0);
	} 
	else if(rchildpid==-1)
	{
		printf("\n right comm child fork failed ");
		exit(1);
	} 

	printf("\n Press any key to continue closing pipefds by parent");
	getchar();
	close(pipefd[0]);
	close(pipefd[1]);
	
	waitpid(rchildpid,&status,0);
        printf("\nParent : Status collected from right child -  %d ",status);
        
	printf("\nParent : Terminating now.");

	return(EXIT_SUCCESS);
}

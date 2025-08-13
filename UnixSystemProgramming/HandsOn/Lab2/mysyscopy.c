/*
 * ii) Write a C program to copy source file to destination file.
 * (Use of open, creat, read, write, close system calls)
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


extern int errno;
#define BUFFSIZE 1


int main(int argc, char *argv[])
{

	int sourceFd, destinationFd;
	char *buf;
	int rn,wn;

	if(argc!=3)
	{
		printf("\n %s: missing file operand ",argv[0]);
		printf("\n Usage: %s %s %s",argv[0],"Source","Destination");
		exit(EXIT_FAILURE);
	}	

	sourceFd=open(argv[1],	O_RDONLY);
	
	//error handling	
	if(sourceFd == -1)
	{
		printf("\n%s: %s: %s [ErrorNo: %d]",argv[0],argv[1],strerror(errno),errno);	
		return(EXIT_FAILURE);
	}
	
	
		
	destinationFd=creat(argv[2],	O_CREAT|O_WRONLY|O_TRUNC|S_IRUSR|S_IWUSR|S_IRGRP|S_IXGRP);
	//destinationFd=open(argv[2],	O_WRONLY|O_CREAT|O_TRUNC);
	
	//error handling	
	if(destinationFd == -1)
	{
		printf("\n%s: %s: %s [ErrorNo: %d]",argv[0],argv[2],strerror(errno),errno);	
		close(sourceFd);
		return(EXIT_FAILURE);
	}


 	
	buf=(char *) malloc(BUFFSIZE*sizeof(char));
	if(buf==NULL)
	{
		printf("\nMemory allocation failure");
		close(sourceFd);
		close(destinationFd);
		exit(EXIT_FAILURE);
	}
	while((rn=read(sourceFd,buf,BUFFSIZE))!=0)
	{
		if(rn==-1)
		{
			printf("\n%s: %s: read failure. %s [ErrorNo: %d]",argv[0],argv[1],strerror(errno),errno);	
			close(sourceFd);
			close(destinationFd);
			return(EXIT_FAILURE);
		}
		
		wn=write(destinationFd, buf,rn);
		if(wn!=rn)
		{
			if(wn==-1)
			{
				printf("\n%s: %s: write failure. %s [ErrorNo: %d]",argv[0],argv[2],strerror(errno),errno);	
				close(sourceFd);
				close(destinationFd);
				return(EXIT_FAILURE);
			}
		}
	}
	
	close(sourceFd);
	close(destinationFd);
	
	free(buf);
	
	return(EXIT_SUCCESS);
	
}

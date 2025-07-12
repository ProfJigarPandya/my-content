/*
 * i) Write a C program to concatenate set of files given as a command line argument to a last file name provided
 *
 * ./a.out source1.txt source2.txt source3.txt ... dest.txt
 *
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

	if(argc<2)
	{
		printf("\n %s: missing file operand ",argv[0]);
		printf("\n Usage: %s %s %s ... %s",argv[0],"Source1","Source2","DestinationNewFileName");
		exit(EXIT_FAILURE);
	}	

	if(argc==2)//Just create empty Destination File
	{	
		destinationFd=creat(argv[1],	O_CREAT|O_WRONLY|O_TRUNC|S_IRUSR|S_IWUSR|S_IRGRP|S_IXGRP);
		close(destinationFd);
		return EXIT_SUCCESS; 
	}
	

	destinationFd=creat(argv[argc-1],	O_CREAT|O_WRONLY|O_TRUNC|S_IRUSR|S_IWUSR|S_IRGRP|S_IXGRP);
	//destinationFd=open(argv[2],	O_WRONLY|O_CREAT|O_TRUNC);
	
	//error handling	
	if(destinationFd == -1)
	{
		printf("\n%s: %s: %s [ErrorNo: %d]",argv[0],argv[argc-1],strerror(errno),errno);	
		return(EXIT_FAILURE);
	}

	buf=(char *) malloc(BUFFSIZE*sizeof(char));
	if(buf==NULL)
	{
		printf("\nMemory allocation failure");
		close(destinationFd);
		exit(EXIT_FAILURE);
	}

	int filecount=1;
	do{

		sourceFd=open(argv[filecount],	O_RDONLY);

		//error handling	
		if(sourceFd == -1)//could not open source file
		{	
			printf("\n%s: FileName %s Position %d : %s [ErrorNo: %d]",argv[0], argv[filecount],filecount+1,strerror(errno),errno);	
			filecount++;
			printf("\n Destination file is in intermediate state. May discard manually.");
			close(destinationFd);
			return(EXIT_FAILURE);
		}
	
	

		while((rn=read(sourceFd,buf,BUFFSIZE))!=0)//EOF
		{
			if(rn==-1)//could not read.
			{
				printf("\n%s: FileName %s Position %d : read failure. %s [ErrorNo: %d]",argv[0],argv[filecount],filecount+1,strerror(errno),errno);	
				printf("\n Destination file is in intermediate state. May discard manually.");
				close(sourceFd);
				close(destinationFd);
				return(EXIT_FAILURE);
			}	
		
			wn=write(destinationFd, buf,rn);
			if(wn!=rn)
			{
				if(wn==-1)
				{
					printf("\n%s: FileName %s Position %d : write failure. %s [ErrorNo: %d]",argv[0],argv[filecount],filecount+1,strerror(errno),errno);	
					close(sourceFd);
					printf("\n Destination file is in intermediate state. May discard manually.");
					close(destinationFd);
					return(EXIT_FAILURE);
				}
			}
		}
	
		close(sourceFd);
		filecount++;

	}while(filecount<(argc-1));

	free(buf);
	close(destinationFd);

	return(EXIT_SUCCESS);
	
}

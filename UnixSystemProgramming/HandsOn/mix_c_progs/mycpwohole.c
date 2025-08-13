/*
Develop a C program using UNIX APIs (preferably system calls)  to copy a file containing 
holes without writing the  bytes  of  0  to  the  output  file. The  source  and  destination  file 
path names  are  provided  as  command  line  arguments. Perform  appropriate  error  handling 
with accurate error messages.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int errno;
int main(int argc, char* argv[])
{
	int fdsrc, fddst, n, i;
	char buff[256];
	if(argc!=3)
	{
		printf("\n Usage: %s sourcefile destfile \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	
	fdsrc = open(argv[1],O_RDONLY);
	if(fdsrc ==-1)
	{
		printf("\n Source open error : %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	fddst = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP);
	if(fddst ==-1)
	{
		printf("\n Destination open error : %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	do
	{
		n=read(fdsrc, buff, 256);
		if(n==-1)
		{
			printf("\n READ STOPPED. : %s\n ", strerror(errno));
			exit(EXIT_FAILURE);
		}	
		else if(n==0)
		{
			printf("\n Reached EOF in source file \n");
			break;	
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(buff[i])//not null
				{
					if(write(fddst, &buff[i], 1)!=1)
					{
						printf("\n Write destination error : %s \n",strerror(errno));
						exit(EXIT_FAILURE);			
					}
					
				}
			}	
		}
	}while(1);
	close(fdsrc);
	close(fddst);

	
	printf("\n Have a nice day!");
	return(EXIT_FAILURE);

}

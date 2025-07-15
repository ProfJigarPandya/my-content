/* Create a dummy file with hole. */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int errno;

int main()
{
	int fd;
	int n,soffset;
	char buffcaps[]="ABCD",buffsmalls[]="abcd";
	fd = open ("source.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP);
	if(fd ==-1)
	{
		printf("\nFile open error : %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	n=write(fd,buffcaps,strlen(buffcaps));
	if(n!=strlen(buffcaps))
	{
		printf("\n Write error : %s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	soffset=lseek(fd,10000,SEEK_END);
	if(soffset==-1)
	{
		printf("\n lseek error : %s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	n=write(fd,buffsmalls,strlen(buffsmalls));
	if(n!=strlen(buffsmalls))
	{
		printf("\n Write error : %s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	close(fd);
	return(0);
}

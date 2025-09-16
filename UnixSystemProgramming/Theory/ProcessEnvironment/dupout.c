#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



extern int errno;
int main()
{
	int newfd =-999;
	int fd = -999;
	fd=open("demo.txt",O_RDWR|O_CREAT);
	if(fd==-1)
	{
		perror("\n Error ");
		exit(1);
	}
	printf("fd open value %d",fd);//3
	fflush(stdout);
	

	close(1);//stdout
	newfd=dup(fd);//
	printf("newfd open value %d",newfd);//1
	fflush(stdout);
	write(1,"He",2);
	close(fd);
	close(newfd);
}


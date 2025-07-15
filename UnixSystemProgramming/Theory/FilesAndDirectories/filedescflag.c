/*
 Print file descriptor flags for specified descriptor. Reading from process table.
FD_CLOEXEC

 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

extern int errno;

int main(int argc, char *argv[])
{
	int mylocalfd;
	int i,ret,dupfd;

	mylocalfd = open("test.temp",O_CREAT|O_RDONLY|O_CLOEXEC);
	if(mylocalfd ==-1)
	{
		printf("\n Error in open() : %s",strerror(errno));
		exit(1);
	}
		

	ret = fcntl(mylocalfd,F_GETFD); //FD - File Descriptor Flags from process table
	if(ret==-1)
	{
		printf("\n Error in fcntl : %s",strerror(errno));
		exit(1);
	}
	else
	{
		printf("\n Original Descriptor %d has flags %d \n", mylocalfd, ret&FD_CLOEXEC);
	}
	
	dupfd = dup(mylocalfd);
	if(dupfd == -1)
	{
		printf("\n Error in dup : %s",strerror(errno));
		exit(1);
	}

	printf("\n Dup fd is %d \n", dupfd);
	
	ret = fcntl(dupfd,F_GETFD); //FD - File Descriptor Flags from process table
	if(ret==-1)
	{
		printf("\n Error in fcntl : %s",strerror(errno));
		exit(1);
	}
	else
	{
		printf("\n Duplicate file Descriptor %d has flags %d \n", dupfd ,ret&FD_CLOEXEC);
	}

	//Set to test the flags set function
	ret |= FD_CLOEXEC;
	if(fcntl(dupfd, F_SETFD, ret) < 0)
	{
		printf("\n fcntl set failed %s",strerror(errno));
		exit(1);
	}
	else
	{
		//retrive and display to confirm
		printf("\n After setting the flag for duplicate fd ");
		
		ret = fcntl(dupfd,F_GETFD); //FD - File Descriptor Flags from process table
        	if(ret==-1)
        	{
                	printf("\n Error in fcntl : %s",strerror(errno));
                	exit(1);
        	}
        	else
        	{
                	printf("\n Duplicate file Descriptor %d has flags %d \n", dupfd ,ret&FD_CLOEXEC);
       		}	
	}

	
	
	return(EXIT_SUCCESS);
}

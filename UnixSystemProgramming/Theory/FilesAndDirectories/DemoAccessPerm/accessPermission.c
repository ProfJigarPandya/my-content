//Access file permission
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>            /* Definition of AT_* constants */
#include <sys/syscall.h>      /* Definition of SYS_* constants */


/*
*/


extern int errno;


int checkFileStatus(const char * pathname, int mode)
{
	int status;

		
	status = access(pathname,mode);
	if(status == -1)
	{
		perror("access api : ");
		exit(1);
		//return (EXIT_FAILURE);	
	}
	else if(status ==0)//success
	{
		return 1; //success
	}
	else
	{
		printf("Error ");
	}
	return 0;//Failure
}
	

int main(int argc, char *argv[])
{
	
	if(checkFileStatus(argv[1],R_OK))
	{
		printf("\n Permission available OK : mode R_OK");
	}
	else
	{
		printf("\n Permission available NOT OK : mode R_OK");
	}
	if(checkFileStatus(argv[1],W_OK))
	{
		printf("\n Permission available OK : mode W_OK");
	}
	else
	{
	
		printf("\n Permission available NOT OK : mode W_OK");
	}
	if(checkFileStatus(argv[1],X_OK))
	{
		printf("\n Permission available OK : mode X_OK");
	}
	else
	{
		
		printf("\n Permission available NOT OK : mode X_OK");
	}
	return(0);
}

/*
Copy standard input to standard output using system calls.
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>



#define BUFFSIZE 4096
int main(void)
{
	int n;
	char buf[BUFFSIZE];
	while((n=read(STDIN_FILENO, buf, BUFFSIZE))>0)
	{
		if(write(STDOUT_FILENO,buf,n) !=n)
		{
			perror("write error");
			return(EXIT_FAILURE);
		}

	}
	
	if(n<0)
	{
		perror("read error");
		return(EXIT_FAILURE);
	}	
	
	return(EXIT_SUCCESS);
}

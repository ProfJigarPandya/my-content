#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>

extern int errno;
//Simple echo command. Read from standard input and display on standard output.
int main()
{
	int ch;
	ssize_t readReturnStatus; //0 indicates End of file; -1 error. ; otherwise count of chars read.
	do
	{
		readReturnStatus = read(0,&ch,1);//File descriptor 0 represents system standard input
		if(readReturnStatus == -1)
		{
			perror("Read failure");
			return (EXIT_FAILURE);
		}	
		if(readReturnStatus == 0)
		{
			printf("\n Have a nice day!");
			break;
		}
		write(1,&ch,1);//File descriptor 1 represents system standard output
		
	}while(1);
	

	return (EXIT_SUCCESS);
}


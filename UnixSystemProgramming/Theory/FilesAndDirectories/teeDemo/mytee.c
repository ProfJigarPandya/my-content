#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


extern int errno;
//Simple tee command. Read from standard input and display on standard output but also store to a file. Directing input to TWO output streams.
//echo "Hello World"  | tee file1.txt file2.txt file3.txt

//echo "Hello World " | ./mytee.o f1.txt f2.txt f3.txt
int main(int argc, char * argv[])
{
	int fds[argc];
	int ch;
	ssize_t readReturnStatus; //0 indicates End of file; -1 error. ; otherwise count of chars read.


	for(int i=1;i<argc;i++)
	{
		fds[i]=open(argv[i],O_CREAT|O_WRONLY);
		if(fds[i]==-1)
		{
			printf(" Open issue for %s - %s",argv[i],strerror(errno));
				exit(EXIT_FAILURE);
		}
	}

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
		for(int i=1;i<=argc;i++)
		{
			write(fds[i],&ch,1);
		}
		write(1,&ch,1);//File descriptor 1 represents system standard output
		
	}while(1);

	
	for(int i=1;i<=argc;i++)
	{
		close(fds[i]);
	}
	

	return (EXIT_SUCCESS);
}


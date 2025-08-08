#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAXLINE 100

extern int errno;

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	system("clear");

	while( fgets(buf, MAXLINE, stdin) != NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) -1 ] = 0;
		}
		
		if((pid = fork()) < 0)
		{
			printf("\n Fork failed ");
			exit(1);
		}
		else if(pid==0)//Child process
		{
			//system(buff);
			if(execlp(buf,buf, (char *)0 ) == -1)
			{
				//err_ret("couldn't execute input command: %s" ,buf);
				printf("Error %s",strerror(errno));
			}
			exit(127);
		}
	}
	
	//if here, that means parent bcoz child has exit 
	if((pid = waitpid(pid, &status, 0))<0)
	{
		printf("Error Msg %s ",strerror(errno));
		printf("\nStatus %d",status);
	}
	printf("\n Good Bye");
	return (0);
}

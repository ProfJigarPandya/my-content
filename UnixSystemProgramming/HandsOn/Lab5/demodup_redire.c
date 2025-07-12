/* Demo redirection to a file using dup command.
  
  gcc demodup_redire.c 
  ./a.out 
  cat temp.txt 
  chown JigarPandya:staff temp.txt 
  chmod 640 temp.txt 
  cat temp.txt 
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

int main()
{
 	int localfilefd,dupfd;
	char msg[]="Hello world, this is demo of redirection using dup.\n";
	localfilefd = open("temp.txt",O_RDWR|O_CREAT);
	if(localfilefd == -1)
	{
		printf("\n Can't open file temp.txt %s\n",strerror(errno));
		exit(1);
	}
	else
	{
		printf("\n Local file fd %d \n", localfilefd);
	}
	
	
	//close stdout for current process, so that can be attached to tempfd.
	close(1);
	
	dupfd = dup(localfilefd);
	
	if(dupfd ==-1)
	{
		printf("\n Can't dup localfilefd %d because %s\n",localfilefd, strerror(errno));
		exit(1);
	}
	else
	{
		printf("\n dupfd %d \n",dupfd);
	}

 	//Write message to stdout (1). But because it is linked to localfilefd as dupfd. Note that output is actually being redirected to file as content.
	
	write(1,msg,strlen(msg));
	
	close(localfilefd);
}

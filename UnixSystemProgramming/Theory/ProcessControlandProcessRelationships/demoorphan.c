//demo orphan process. 
// parent of orphan process is 1 (init)
//ps axl | grep demoorphan

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
extern int errno;
int main()
{
	int pid;
	printf("\n Hi from main program. ");
	if((pid=fork())<0)
	{
		printf("\n Fork error %s ",strerror(errno));
		exit(1);
	}
	else if (pid!=0)//parent
	{	
		exit(0);
	}
	else//child
	{
		sleep(15);
	}
	return(0);
}

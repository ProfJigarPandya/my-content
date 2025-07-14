#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

extern int errno;
int main()
{
	printf("\n Welcome \n");
	//if((execve("/bin/date",NULL,NULL)==-1))
	/*if((system("date")==-1))
	{
		printf("System failed %s ",strerror(errno));
		exit(1);
	}*/
	if((execve("/bin/date",NULL,NULL)==-1))
	{
		printf("Execve failed %s ",strerror(errno));
		exit(1);
	}
	printf("\n Good Bye \n");

}

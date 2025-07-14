#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
extern int errno;
int main()
{
	printf("\n Welcome \n");
	//if((execve("/bin/date",NULL,NULL)==-1))
	if((execve("date",NULL,NULL)==-1))
	{
		printf("Execve failed %s ",strerror(errno));
	}
	printf("\n Good Bye \n");

}

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//extern char *sys_siglist[];
void handler(int signno);
int main()
{
	int a=15;
	int b=0;
	int c;	
	
	signal(SIGFPE,handler);
	printf("\n pid %d\n", getpid());
	c=a/b;

	printf("\n Demo signal handler using divide by zero exception ");
}
void handler(int signno)
{
	char buff[128];
	printf("\nArray %s",sys_siglist[signno]);
	printf("\n Handler: %d  %s ",signno,strsignal(signno));
	//sig2str(signno,buff);
	//printf("\n sig2str %s ",buff);
	exit(1);
	//return;
}

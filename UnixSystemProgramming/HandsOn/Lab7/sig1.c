#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int signno);
int main()
{
	int a=15;
	int b=0;
	int c;	
	
	//signal(SIGFPE,handler);
	printf("\n pid %d\n", getpid());
	c=a/b;

	printf("\n Demo signal handler using divide by zero exception ");
}
void handler(int signno)
{
	printf("\n Handler: %d ",signno);
	exit(1);
}

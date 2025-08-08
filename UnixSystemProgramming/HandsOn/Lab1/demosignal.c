#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void handler(int a);
int main()
{
	int a=15;
	int b=0;
	int c;	
	
	signal(SIGFPE,handler);
	
	c=a/b;

	printf("\n Demo signal handler using divide by zero exception ");
}
void handler(int a)
{
	printf("\n Handler: %d ",a);
	//exit(1);
}

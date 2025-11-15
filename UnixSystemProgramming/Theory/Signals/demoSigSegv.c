#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void myArrayIndexOutOfBoundHandler(int signo);

int main()
{
	int array[50000]={10,20,30,40,50};
	sighandler_t retstat=NULL;
	retstat=signal(SIGSEGV,myArrayIndexOutOfBoundHandler);
	if(retstat==NULL)
	{
		perror("\n Error in disposition of signal");
		exit(EXIT_FAILURE);
	}
	for(int i=1;i<=50000;i++)
	{
		printf("\n %d ",array[i]);
	}
	pause();
	return 0;
}
void myArrayIndexOutOfBoundHandler(int signo)
{
	printf("\n Hey possibly array index out of bound detected because SIGSEGV has been received from OS");
	printf("\n Press any key to continue ");
	getchar();
}

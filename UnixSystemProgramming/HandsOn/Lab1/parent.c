#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	for(i=1;i<argc;i++)
	{
		printf("\n Parent (%d) : Argument %d \n",getpid(),i);
		if(fork()==0)
		{
			printf("\n Child (%d): Argument value %s \n",getpid(),argv[i]);
			exit(127);
		}
	}
	printf("\n Press key to exit. ");
	getchar();
}

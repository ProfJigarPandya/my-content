#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main(int argc, char *argv[])
{
	int i;
	printf("\n Command line arguments \n");
	for(i=0;((i<argc) || (argv[i]!=NULL));i++)
	{
		printf("%s\n",argv[i]);
	}
	
	printf("\n Environment variables \n");
	for(i=0;((environ[i]!=NULL));i++)
	{
		printf("%s\n",environ[i]);
	}
	
	printf("\n Usage of getenv function ");
	printf("\n HOME %s ",getenv("HOME"));
	
}

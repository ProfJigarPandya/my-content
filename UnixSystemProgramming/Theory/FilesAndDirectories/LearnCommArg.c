#include <stdio.h>
int main(int argc, char* argv[])
{
	printf("Hello World");
	printf("\n Total number of arguments including program name is %d ",argc);
	for(int i=0;i<argc;i++)
	{
		printf("\n%d %s",i,argv[i]);
	}
	return 0;
}


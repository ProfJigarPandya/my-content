#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char *ptr;
	if(argc<=1)
	{
		printf("\n Usage: command env1 env2 ...");
		return 1;
	}
	for(int i=1;i<argc;i++)
	{
		ptr=getenv(argv[i]);
		if(!ptr)
		{
			printf("\n Invalid environment variable %s ",argv[i]);
		}
		else
			printf("\n Environment variable %s value is %s ",argv[i],getenv(argv[i]));
	}
	return 0;
}

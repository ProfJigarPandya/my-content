#include <stdio.h>
#include <stdlib.h>

extern char ** environ;

int main()
{
	char ** var;

	for(var = environ; *var != NULL; var++)
		printf("%s\n", *var);

	exit(EXIT_SUCCESS);
}


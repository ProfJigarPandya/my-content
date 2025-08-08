#include <stdio.h>
#include <stdlib.h>

/*
	You can run the program by exporting the environment
	variable by: export a = 10
	./a.out | grep a=10
*/
int main(int argc, char**argv, char **envp)
{
	argc = argc; /* To avoid warning/error 'unused paramter argc'*/
	argv = argv; /* To avoid warning/error 'unused paramter argv' */

	for(int i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);

	exit(EXIT_SUCCESS);
}


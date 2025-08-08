#include "../pmj.h"

/*
./a.out HOME LOGNAME USER PWD
*/
int main(int argc, char **argv)
{
	char *env_value;

	if (argc == 1) {
		fprintf(stderr, "Usage: ./a.out <env_variable(s)>\n");
		exit(EXIT_FAILURE);
	}

	for(int i=1; i < argc; i++) {
		if ((env_value = getenv(argv[i])) != NULL)
			printf("%s=%s\n", argv[i], env_value);
		else
			printf("%s is not an environment variable\n", argv[i]);
	}
	exit(EXIT_SUCCESS);
}


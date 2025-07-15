#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv)
{
	char *s;

	for(int i = 1; i < argc; i++) {
		s = getenv(argv[i]);
		assert(s != NULL);
		printf("%s=%s\n", argv[i], s);
	}
	exit(EXIT_SUCCESS);
}


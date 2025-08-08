#include "../pmj.h"

#define SIZE	256

int main()
{
	char path[SIZE];

	if ( getcwd(path, SIZE) == NULL )
		err_quit("getcwd");

	printf("%s\n", path);

	exit(EXIT_SUCCESS);
}


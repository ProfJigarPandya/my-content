#include "../pmj.h"

int main()
{
	char *home;

	home  = getenv("HOME");
	
	if (home != NULL)
		printf("\nHOME = %s\n", home);

	exit(EXIT_SUCCESS);	
}


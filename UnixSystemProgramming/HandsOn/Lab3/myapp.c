/* Test program to be executed by child process of main.
 * gcc myapp.c -o myapp.o
 */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int i;
	printf("\n My application to print command line arguments ");
	fflush(stdout);
	if(argc==0)
	{
		printf("\n No arguments supplied. ");
	}
	else
	{

		for(i=0;i<argc;i++)
			printf("\n%d - %s ",i+1,argv[i]);
	}

	printf("\n Have a nice day!\n");

	fflush(stdout);
	return(EXIT_SUCCESS);
}

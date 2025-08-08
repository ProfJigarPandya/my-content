#include "../pmj.h"

int main()
{
	struct stat statbuf;

	/* set absolute mode to rw-rw---- */
	if ( chmod("abc.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) < 0) 
		err_quit("chmod('abc.txt')");

	if ( stat("fruits.txt", &statbuf) < 0)
		err_quit("stat('fruits.txt')");

	/* turn off read permission for others*/
	if ( chmod("fruits.txt", statbuf.st_mode & ~S_IROTH) < 0) 
		err_quit("chmod('fruits.txt')");
	
	exit(EXIT_SUCCESS);
}


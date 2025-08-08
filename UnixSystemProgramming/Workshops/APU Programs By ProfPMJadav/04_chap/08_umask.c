#include "../pmj.h"

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
	umask(0); // umask 0

	/* mode & ~umask = 666 & ~0 = 666 & 777 = 666*/
	if (creat("apples.txt", RWRWRW) < 0)
		err_quit("creat('apples.txt')");

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // umask 066

	/* mode & ~umask = 666 & ~066 = 666 & 711 = 600*/
	if (creat("oranges.txt", RWRWRW) < 0) 
		err_quit("creat('oranges.txt')");

	exit(EXIT_SUCCESS);
}


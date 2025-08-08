#include "../pmj.h"

int main()
{
	if (rmdir("newdir") == -1)
		err_quit("rmdir('newdir')");
	
	exit(EXIT_SUCCESS);
}


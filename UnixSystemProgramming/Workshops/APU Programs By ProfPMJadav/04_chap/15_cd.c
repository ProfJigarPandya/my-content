#include "../pmj.h"

int main()
{
	if (chdir("/tmp") < 0)
		err_quit("chdir('/tmp')");

	execl("/usr/bin/ls", "ls", "-l", NULL);
	
	exit(EXIT_SUCCESS);
}


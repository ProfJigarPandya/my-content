#include "../pmj.h"

int main()
{
	if (mkdir("newdir", S_IRUSR | S_IWUSR | S_IXUSR) == -1)
		err_quit("mkdir('newdir')");
	
	exit(EXIT_SUCCESS);
}


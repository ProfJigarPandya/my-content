#include "../pmj.h"

int main()
{
	struct stat buf;
	char *ptr = "unknown";

	if (lstat("abc.txt", &buf) < 0)
		err_quit("lstat('abc.txt')");
	
	if (S_ISREG(buf.st_mode))
		ptr = "regular";

	printf("\nFile type of abc.txt: %s\n", ptr);
	
	return 0;
}


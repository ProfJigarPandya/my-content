#include "..//pmj.h"

int main(int argc, char **argv)
{
	struct stat buf;
	char *ptr = "unknown";

	for(int i=1; i < argc; i++) {
		printf("\nFile: %s", argv[i]);
		if (lstat(argv[i], &buf) < 0)
			err_quit("lstat");

		if (S_ISREG(buf.st_mode))
			ptr = "regular";
		else
			ptr = "unknown";

		printf("\nFile type: %s\n", ptr);
	}
	
	exit(EXIT_SUCCESS);
}


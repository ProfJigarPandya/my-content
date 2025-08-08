#include "../pmj.h"

int main(int argc, char **argv)
{
	int i;
	struct stat buf;
	char *ptr;

	if (argc == 1) {
		printf("Usage: ./a.out <file(s)>\n");
		exit(EXIT_SUCCESS);
	}
	for(i=1; i<argc; i++) {
		printf("\nFile: %s", argv[i]);
		if (lstat(argv[i], &buf) < 0)
			err_quit("lstat");

		if (S_ISREG(buf.st_mode))
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "unknown mode";

		printf("\nFile type: %s\n", ptr);
	}
	exit(EXIT_SUCCESS);
}


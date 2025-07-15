#include "../pmj.h"

/* 
./a.out abc.txt / /dev/loop1 /dev/tty 
*/
int main(int argc, char **argv)
{
	struct stat buf;
	char *ptr;

	for(int i = 1; i < argc; i++) {
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

		printf("File type of %-15s:  %s\n", argv[i], ptr);
	}
	
	exit(EXIT_SUCCESS);
}


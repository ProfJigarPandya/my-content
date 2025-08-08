#include "../pmj.h"

int main(int argc, char **argv)
{
	int i;
	struct stat buf;

	for(i=1; i<argc; i++) {
		printf("\nFile: %s", argv[i]);
		if (lstat(argv[i], &buf) < 0)
			err_quit("lstat");

		if (S_IRUSR & buf.st_mode)
			printf("\nUser can read");
		if (S_IWUSR & buf.st_mode)
			printf("\nUser can write");
		if (S_IXUSR & buf.st_mode)
			printf("\nUser can execute");
		if (S_IRGRP & buf.st_mode)
			printf("\nGroup can read");
		if (S_IWGRP & buf.st_mode)
			printf("\nGroup can write");
		if (S_IXGRP & buf.st_mode)
			printf("\nGroup can execute");
		if (S_IROTH & buf.st_mode)
			printf("\nOthers can read");
		if (S_IWOTH & buf.st_mode)
			printf("\nOthers can write");
		if (S_IXOTH & buf.st_mode)
			printf("\nOthers can execute");

		printf("\n\n");
	}
	exit(EXIT_SUCCESS);	
}


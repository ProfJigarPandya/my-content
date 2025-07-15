#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd;

	fd = open("abc.txt", O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "Error no.: %d\n", errno);
		fprintf(stderr, "open('abc.txt'): %s\n", strerror(errno));
		return 1;
	}

	close(fd);
	return 0;
}


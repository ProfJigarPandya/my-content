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
		perror("open('abc.txt')");
		return 1;
	}

	printf("'abc.txt' file opened successfully\n");

	close(fd);

	return 0;
}


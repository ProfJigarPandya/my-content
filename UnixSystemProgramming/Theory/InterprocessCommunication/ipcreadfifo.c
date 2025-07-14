/*
 * Inter Process Communications (Use of pipe, and mkfifo system calls)
 * 
 * Reading from already created fifo.
 * 
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX 100

int 
main()
{
	char		buff      [MAX];
	int		fd;
	int		msglen;

	fd = open("./testfifo", O_RDONLY);
	//read only

		if (fd == -1 && errno != EEXIST) {
		printf("\n Error in opening fifo for reading. ");
		return (1);
	}
	strcpy(buff, "");
	msglen = read(fd, buff, MAX);

	if (msglen > 0) {
		printf("\nRead following msg from fifo: ");
		printf("%s", buff);
	} else
		printf("Fifo is empty. Could not read anything. ");

	close(fd);
	unlink("./testfifo");
	//delete a name and possibly the file it refers to

		return 0;
}

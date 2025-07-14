/*
 * Inter Process Communications (Use of pipe, and mkfifo system calls)
 * 
 * Write to fifo. Using another program read the content from the fifo and
 * display on the screen.
 * mkfifo ./testfifo
 * gcc ipcwritefifo.c -o writer.o
 * gcc ipcreadfifo.c -o reader.o
 * In one window run, ./writer.o
 * In another window run, ./reader.o  
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
	int		fr = mkfifo("./testfifo", 0666);
	if (fr == -1 && errno != EEXIST) {
		printf("\n Error in creating fifo");
		return (1);
	}
	if (fr > 0)
		return (1);

	fd = open("./testfifo", O_WRONLY);
	//write only

		if (fd == -1) {
		printf("\n Error in opening fifo for writing");
		return (1);
	}
	strcpy(buff, "Hi, written this message to fifo testfifo.Testing IPC.");
	write(fd, buff, MAX);

	close(fd);
	unlink("./testfifo");
	//delete a name and possibly the file it refers to

	return 0;
}

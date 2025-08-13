#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/*
 Shell commands : 
man 2 syscalls
man 2 mkdir
man mode_t
man open
man 3 errno
man 3 perror
EEXIST
EACCES
echo $?
*/

extern int errno;
int main()
{
	int  status = mkdir ("demodir",S_IRWXU);
	perror("\n my mkdir");
	printf("\n my mkdir status %d with errno encountered %d",status,errno);

	return 0;
}



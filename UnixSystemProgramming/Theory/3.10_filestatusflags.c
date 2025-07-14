/*
 Print file status flags for specified descriptor. Reading from file table.

3.10_filestatusflags.o 0 < /dev/tty
3.10_filestatusflags.o 1 > temp.foo
cat temp.foo
echo "">temp.foo
3.10_filestatusflags.o 2 2>>temp.foo

note the difference
3.10_filestatusflags.o 2 2 >> temp.foo
cat temp.foo

echo "">temp.foo
3.10_filestatusflags.o 5 5<>temp.foo
cat temp.foo

 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

extern int errno;

int main(int argc, char *argv[])
{
	
	int i,ret;
	if(argc<2)
	{
		printf("\n Usage: %s %s ",argv[0],"<filedescriptor>");
		exit(1);
	}
	for(i=0;i<argc;i++)
		printf("\n %d %s ",i,argv[i]);
	ret = fcntl(atoi(argv[1]),F_GETFL); //FL - File Status Flags from file table
	if(ret==-1)
	{
		printf("\n Error in fcntl : %s",strerror(errno));
		exit(1);
	}
	else
	{
		int r = ret&(O_ACCMODE);
		if(r ==O_RDONLY)
		{
			printf("\n read only\n");
		}
		else if(r == O_WRONLY)
		{
			printf("\n write only\n");
		}
		else if(r == O_RDWR)
		{
			printf("\n read write\n" );
		}
		else
		{
			printf("%d",ret);
		}
		
		if(  ret&O_APPEND)
		{
			printf(", append \n");
		}
		
		if( ret&O_NONBLOCK)
		{
			printf(", nonblocking \n");
		}
	
		#if defined(O_SYNC)
			if (ret & O_SYNC)
				printf(", synchronous writes");
		#endif
		#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
			if (ret & O_FSYNC)
				printf(", synchronous writes");
		#endif
		putchar('\n');
	}
	return(EXIT_SUCCESS);
}

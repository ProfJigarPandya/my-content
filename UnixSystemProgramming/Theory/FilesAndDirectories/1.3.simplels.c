#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
/*
 man 2 getdent

   struct linux_dirent {
               unsigned long  d_ino;     /* Inode number */
               unsigned long  d_off;     /* Not an offset; see below */
               unsigned short d_reclen;  /* Length of this linux_dirent */
               char           d_name[];  /* Filename (null-terminated) */
                                 /* length is actually (d_reclen - 2 -
                                    offsetof(struct linux_dirent, d_name)) */
               /*
               char           pad;       // Zero padding byte
               char           d_type;    // File type (only since Linux
                                         // 2.6.4); offset is (d_reclen - 1)
               */
           }
*/

extern int errno;
int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc!=2)
	{
		printf("Usage: %s directory_name",argv[0]);
		exit(EXIT_FAILURE);
	}

	if((dp=opendir(argv[1])) == NULL)
	{
		printf("\n Error code %d",errno);
		printf("can't open %s. Error Msg: %s",argv[1],strerror(errno));
		exit(EXIT_FAILURE);
	}

	while((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n",dirp->d_name);
	}
	
	closedir(dp);
	
	exit(EXIT_SUCCESS);
}

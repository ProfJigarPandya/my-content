#include <stdio.h>

//man 2 lstat
#include <sys/stat.h>

#include <errno.h>
#include <time.h>

extern int errno;


int findTypeOfFile(char *filename)
{
	int status=-2;
	struct stat statbuf;
	
	status = lstat(filename,&statbuf);
	if(status==-1)
	{
		perror(filename);
		return -1;
	}
	else
	{
		printf("\n%s File type:                ",filename);

		switch (statbuf.st_mode & S_IFMT) {
        		case S_IFBLK:  printf("block device\n");            break;
			case S_IFCHR:  printf("character device\n");        break;
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
           }

           printf("\nLast status change:       %s", ctime(&statbuf.st_ctime));
           printf("\nLast file access:         %s", ctime(&statbuf.st_atime));
           printf("\nLast file modification:   %s", ctime(&statbuf.st_mtime));


	}
	return 0;
}

int main()
{

	printf("\n%d",findTypeOfFile("HelloWorld.c"));
	printf("\n%d",findTypeOfFile("regularfile.txt"));
	printf("\n%d",findTypeOfFile("a.out"));
	printf("\n%d",findTypeOfFile("/usr/bin/touch"));
	printf("\n%d",findTypeOfFile("/proc/meminfo"));
	printf("\n%d",findTypeOfFile("directoryfile"));
	printf("\n%d",findTypeOfFile("/dev/pts/1"));
	printf("\n%d",findTypeOfFile("/dev/null"));
	printf("\n%d",findTypeOfFile("/dev/nvme0n1"));
	printf("\n%d",findTypeOfFile("namedpipefile"));
	printf("\n%d",findTypeOfFile("/var/run/rpcbind.sock"));
	printf("\n%d",findTypeOfFile("demoactualfile1"));
	printf("\n%d",findTypeOfFile("demohardlinktofile1"));
	printf("\n%d",findTypeOfFile("demosoftlinktofile1"));
	return 0;
}


#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


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

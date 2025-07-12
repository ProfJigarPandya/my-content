/*
 * Write a C program to display files and directories from the current directory.
 * (Use of opendir, readdir, closedir system calls)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>


extern int errno;

void display(DIR *dirp,char *path);
int main(int argc,char *argv[])
{
	DIR *dirp;
	

  	if (argc != 2)
    	{
      		fprintf (stderr, "Usage: %s <pathname>\n", argv[0]);
	      	exit (EXIT_FAILURE);
    	}

	dirp = opendir(argv[1]);

	if(dirp==NULL)
	{
		printf("\n Opendir failed. ");
		printf("%s",strerror(errno));
		return(EXIT_FAILURE);
	}
	

	display(dirp,argv[1]);

	closedir(dirp);
	
	printf("\n Good Bye!");
	return (EXIT_SUCCESS);
}
void display(DIR *dirp,char *path)
{
	struct stat sb;
	DIR *dirpi;
	struct dirent *pdirent;
	char fullpathwname[512];
	printf("\n%s:\n",path);
	do
	{
	
		strcpy(fullpathwname, path);
		pdirent = readdir(dirp);
		if(pdirent==NULL)
		{
			break;
		}
		
		if( (strcmp(pdirent->d_name,".")==0) || (strcmp(pdirent->d_name,"..")==0))
			continue;
		printf("%s\t", pdirent->d_name);

		strcat(strcat(fullpathwname,"/"),pdirent->d_name);
		// = dirfd(dirp);	
  		if (stat (fullpathwname, &sb) == -1)
    		{
      			perror ("stat");
	      		exit (EXIT_FAILURE);
	    	}
	
		if( (sb.st_mode & S_IFMT) == S_IFDIR)
		{
	
			//printf("\nFPWN: %s",fullpathwname);
			dirpi = opendir(fullpathwname);
			if(dirpi==NULL)
			{
				printf("\n Opendir failed. ");
				printf("%s",strerror(errno));
				return;
			}
			display(dirpi,fullpathwname);	
			closedir(dirpi);
		}
	}while(1);
	printf("\n");
			
}	

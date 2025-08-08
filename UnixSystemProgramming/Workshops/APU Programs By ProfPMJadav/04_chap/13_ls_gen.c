#include "../pmj.h"

/*
struct dirent {
	ino_t          d_ino;       // Inode number 
    off_t          d_off;       // Not an offset; see below 
    unsigned short d_reclen;    // Length of this record 
   	unsigned char  d_type;      // Type of file; not supported
                                   by all filesystem types 
   	char           d_name[256]; // Null-terminated filename 
};
*/
int main(int argc, char **argv)
{
	DIR *dirp;
	struct dirent *dire;
	char *path = NULL;

	if (argc == 2)
		path = argv[1];
	else
		path = ".";

	dirp = opendir(path);
	if (dirp == NULL)
		err_quit("opendir");
	
	while ( (dire = readdir(dirp)) != NULL) {
		printf("%ld \t %s\n", dire->d_ino, dire->d_name);
	}
	
	closedir(dirp);
	exit(EXIT_SUCCESS);
}


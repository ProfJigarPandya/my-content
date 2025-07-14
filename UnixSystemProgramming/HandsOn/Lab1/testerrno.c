//Error handling with a smooth message on the screen makes programmer different from others.

//Trying to open a file, which does not exist.
//Open returns -1 on failure and sets errno
//Using errno and strerror(), we will retrieve the OS error message and print on the screen.
//perror is a linux command, which also shows message text for given code. 
//i.e.
//[jpandya@localhost ~]$ perror 2
//OS error code   2:  No such file or directory
//[jpandya@localhost ~]$ 

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd=open("notpresent.txt",O_RDONLY);
	if(fd==-1)
	{
		printf("\n Open failed. \n Error code is %d and corresponding message from errno.h is %s\n",errno, strerror(errno));
		return(EXIT_FAILURE);
	}	

	printf("\n File was opened successfully in reading mode.\n");

	return(EXIT_SUCCESS);//0

}

/*
Sample Run:

[jpandya@localhost errno]$ ll
total 20
-rwxrwxr-x 1 jpandya jpandya 5543 Dec 18 11:15 a.out
-rw-rw-r-- 1 jpandya jpandya  923 Dec 18 11:15 testerrno.c
[jpandya@localhost errno]$ ./a.out 

 Open failed. 
 Error code is 2 and corresponding message from errno.h is No such file or directory
[jpandya@localhost errno]$ 

*/

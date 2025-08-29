//Access file permission
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>            /* Definition of AT_* constants */
#include <sys/syscall.h>      /* Definition of SYS_* constants */


/*
man 2 chmod
       S_ISUID  (04000)  set-user-ID (set process effective user ID on execve(2))

       S_ISGID  (02000)  set-group-ID  (set  process  effective  group  ID on execve(2); mandatory
                         locking, as described in fcntl(2); take a new file's  group  from  parent
                         directory, as described in chown(2) and mkdir(2))

       S_ISVTX  (01000)  sticky bit (restricted deletion flag, as described in unlink(2))

       S_IRUSR  (00400)  read by owner

       S_IWUSR  (00200)  write by owner

       S_IXUSR  (00100)  execute/search by owner ("search" applies for directories, and means that
                         entries within the directory can be accessed)

       S_IRGRP  (00040)  read by group

       S_IWGRP  (00020)  write by group

       S_IXGRP  (00010)  execute/search by group

       S_IROTH  (00004)  read by others

       S_IWOTH  (00002)  write by others

       S_IXOTH  (00001)  execute/search by others
*/


extern int errno;


void checkFileStatus(const char * pathname, int mode)
{
	int status;

		
	status = access(pathname,mode);
	if(status == -1)
	{
		perror("access api : ");
		exit(1);
		//return (EXIT_FAILURE);	
	}
	else if(status ==0)//success
	{
		return 1; //success
	}
	else
	{
		printf("Error ");
	}
	return 0;//Failure
}
	

int main(int argc, char *argv[])
{
	
	if(checkStatus(argv[1],S_IRUSR))
	{
		
		printf("Permission available OK : mode S_IRUSR");
	}
	return(0);
}

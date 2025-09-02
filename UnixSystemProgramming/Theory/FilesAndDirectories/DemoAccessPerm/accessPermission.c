//Access file permission
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>            /* Definition of AT_* constants */
#include <sys/syscall.h>      /* Definition of SYS_* constants */



/*
man 2 access

The check is done using the calling process's real UID and GID, rather than the effective IDs as is  done  when  actually
       attempting  an  operation (e.g., open(2)) on the file.  Similarly, for the root user, the check uses the set of permitted
       capabilities rather than the set of effective capabilities; and for non-root users, the check uses an empty set of  capa‐
       bilities.

       This  allows  set-user-ID programs and capability-endowed programs to easily determine the invoking user's authority.  In
       other words, access() does not answer the "can I read/write/execute this file?" question.  It answers a slightly  differ‐
       ent  question:  "(assuming  I'm  a setuid binary) can the user who invoked me read/write/execute this file?", which gives
       set-user-ID programs the possibility to prevent malicious users from causing them to read files which users shouldn't  be
       able to read.

root@aharnish:~# ls -l /bin/ping
-rwsr-xr-x 1 root root 64424 Jun 28  2019 /bin/ping

Note about ping like utility owner has s flag setuid instead x.


*/


extern int errno;


int checkFileStatus(const char * pathname, int mode)
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


	if(checkFileStatus(argv[1],F_OK))
	{
		printf("\n Permission available OK : mode F_OK ==> File exists ");
	}
	else
	{
		printf("\n Permission available NOT OK : mode R_OK ==> File does not exist");
	}
	
	if(checkFileStatus(argv[1],R_OK))
	{
		printf("\n Permission available OK : mode R_OK ==> File is readable");
	}
	else
	{
		printf("\n Permission available NOT OK : mode R_OK ==> File is not readable");
	}
	if(checkFileStatus(argv[1],W_OK))
	{
		printf("\n Permission available OK : mode W_OK ==> File is writeable");
	}
	else
	{
	
		printf("\n Permission available NOT OK : mode W_OK ==> File is not writeable");
	}
	if(checkFileStatus(argv[1],X_OK))
	{
		printf("\n Permission available OK : mode X_OK ==> File is executable/explorable");
	}
	else
	{
		
		printf("\n Permission available NOT OK : mode X_OK ==> File is not executable/explorable");
	}

	//You may also combine using a mask consisting of the bitwise  OR of one or more of R_OK, W_OK, and X_OK.
	

	return(0);
}

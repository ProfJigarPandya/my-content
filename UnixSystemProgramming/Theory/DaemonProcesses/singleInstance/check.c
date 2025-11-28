#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/file.h>

extern int errno;
int lockfile(int);

int check(void)
{
	int fd;
	char buf[16+1];


	fd = open ("/var/run/echodaemon.pid",O_RDWR|O_CREAT, (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH));
	if(fd<0)
	{
		//can't open ; system error
		syslog(LOG_ERR,"..........PID FILE open() ERROR: %s.........",strerror(errno));
		exit(1);
	}
	


	/*     struct flock {
               ...
               short l_type;     Type of lock: F_RDLCK,
                                   F_WRLCK, F_UNLCK 
               short l_whence;   How to interpret l_start:
                                   SEEK_SET, SEEK_CUR, SEEK_END 
               off_t l_start;    Starting offset for lock 
               off_t l_len;      Number of bytes to lock 
               pid_t l_pid;      PID of process blocking our lock
                                   (set by F_GETLK and F_OFD_GETLK) 
               ...
           };*/

	struct flock fl;
	fl.l_type=F_WRLCK;
	fl.l_pid = -999;

	int lockstatus=-999;
	//On success, zero is returned.  On error, -1 is returned, and errno is set  to  indicate the error.
	if((lockstatus=fcntl(fd,F_SETLK,&fl))==0)
	{
		syslog(LOG_INFO,"..........LOCK SUCCESS ..........");
		return 0;
	}
	else if(lockstatus == -1)
	{
		//EACCES or EAGAIN Operation is prohibited by locks held by other processes.
		if(errno == EACCES || errno ==EAGAIN)
		{
			syslog(LOG_ERR,"..........IF LOCK FAILURE  %s ....... ",strerror(errno));
			close(fd);
			return (1);
		}
		else
		{
			syslog(LOG_ERR,"..........ELSE LOCK FAILURE  %s ....... ",strerror(errno));
			exit(1);
		}	
	}
	else
	{
		
			syslog(LOG_ERR,"..........LOCK status lockstatus %d  error %s pid %d....... ",lockstatus,strerror(errno),fl.l_pid);
	}
	
	
	ftruncate(fd,0);
	sprintf(buf,"%ld",(long)getpid());
	write(fd,buf,strlen(buf)+1);

	return 0;	
		
}


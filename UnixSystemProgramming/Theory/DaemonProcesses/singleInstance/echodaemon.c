/* The purpose of this daemon is to provide echo service.
It has logic to confirm on the fact taht there will be only single instance up and running. It achieves this by .pid file in lockmode => S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH 

*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

#include "daemonize.h"
#include "check.h"
int main(int argc, char * argv[])
{
	printf("\n I am echo daemon ");	
	openlog ("ECHODAEMON", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_SYSLOG);
	syslog(LOG_ERR,"..............BEFORE RUNNING DAEMONIZE...........");
	daemonize(argv[0]);

	syslog(LOG_ERR,"..............AFTER RUNNING DAEMONIZE............");
	if(check())
	{
		syslog(LOG_ERR, "..........ANOTHER DAEMON NOT ALLOWED ...........");
		exit(1);
	}
	
	

	while(1)
	{
		sleep(10);
		syslog(LOG_INFO,"......... ECHO DAEMON RUNNING ..........");
	}
}

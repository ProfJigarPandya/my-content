#include <stdio.h>
#include <syslog.h>
#include <unistd.h>


int main()
{
	//setlogmask (LOG_UPTO (LOG_NOTICE));
	printf("\n Hello ");
	//openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_SYSLOG);

	syslog (LOG_EMERG, "LOG_EMERG A tree falls in a forest");
	syslog (LOG_ALERT, "LOG_ALERT A tree falls in a forest");
	syslog (LOG_CRIT, "LOG_CRIT A tree falls in a forest");
	syslog (LOG_ERR, "LOG_ERR A tree falls in a forest");
	syslog (LOG_WARNING, "LOG_WARNING A tree falls in a forest");
	syslog (LOG_NOTICE, "LOG_NOTICE A tree falls in a forest");
	syslog (LOG_INFO, "LOG_INFO A tree falls in a forest");
	syslog (LOG_DEBUG, "LOG_DEBUG A tree falls in a forest");
	
	printf("\n Bye ");
	closelog();
	getchar();
}

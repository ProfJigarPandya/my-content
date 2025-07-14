//To demo daemon
//ps -ajx | grep demodaemon
//In above results, find pid and note that tty is not set for daemon. Shows (?)
//To recode signIn time
//kill -SIGUSR1 <pid>
//To record signOut time
//kill -SIGUSR2 <pid>
//To see the logs as root user
//tail -f /var/log/messages
//Code courtesy Ch13. Advanced Programming in the UNIX Env. By Stevens and Rago.
//To destroy daemon: kill -9 <pid>
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

void daemonize(const char *cmd);
void signIn(int signo);
void signOut(int signo);
int main(int argc, char *argv[])
{
	printf("\n Program to demo daemon pid %d",getpid() );
	daemonize(argv[0]);
}

void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t	pid;
	struct rlimit	rl;
	struct sigaction	sa;
	/*
	 * * Clear file creation mask.
	 * */
	umask(0);
	/*
	 * * Get maximum number of file descriptors.
	 * */
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
	{
		printf("%s: can't get file limit", cmd);
		exit(1);
	}
	/*
	 * * Become a session leader to lose controlling TTY.
	 * */
	if ((pid = fork()) < 0)
	{
		printf("%s: can't fork", cmd);
		exit(1);
	}
	else if (pid != 0) /* parent */
		exit(0);
	setsid();
	/*
	 * * Ensure future opens won't allocate controlling TTYs.
	 * */
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
	{
		printf("%s: can't ignore SIGHUP");
		exit(1);
	}
	if ((pid = fork()) < 0)
	{
		printf("%s: can't fork", cmd);
		exit(1);
	}
	else if (pid != 0) /* parent */
		exit(0);
	/*
	 * * Change the current working directory to the root so
	 * * we won't prevent file systems from being unmounted.
	 * */
	if (chdir("/") < 0)
	{
		printf("%s: can't change directory to /");
		exit(1);
	}
	/*
	 * * Close all open file descriptors.
 	* */
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i = 0; i < rl.rlim_max; i++)
		close(i);
	/*
	 * * Attach file descriptors 0, 1, and 2 to /dev/null.
	 * */
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);
	/*
	 * * Initialize the log file.
	 * */
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d",fd0, fd1, fd2);
		exit(1);
	}

	//Task to be performed by daemon unitl alive
	signal(SIGUSR1,signIn);
	signal(SIGUSR2,signOut);
	while(1);
}

void signIn(int signo)
{
	time_t t;
	char buff[256];
	time(&t);
	
	sprintf(buff,"User signed in at %s",ctime(&t));
	syslog(LOG_INFO,buff);		
}

void signOut(int signo)
{
	time_t t;
	char buff[256];
	time(&t);
	
	sprintf(buff,"User signed out at %s",ctime(&t));
	syslog(LOG_INFO,buff);		
}

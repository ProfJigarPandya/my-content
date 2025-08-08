#include "../pmj.h"

void daemonize(const char *);

int main(void)
{
	daemonize("testd");
	pause();
}
void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;
	time_t cur_time;

	/*
	* Clear file creation mask.
	*/
	umask(0);
	/*
	* Get maximum number of file descriptors.
	*/
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
		err_quit("can’t get file limit");
	/*
	* Become a session leader to lose controlling TTY.
	*/
	if ((pid = fork()) < 0)
		err_quit("Can’t fork");
	else if (pid != 0) /* parent */
		exit(0);
	setsid();
	/*
	* Ensure future opens won’t allocate controlling TTYs.
	*/
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("can’t ignore SIGHUP");
	if ((pid = fork()) < 0)
		err_quit("can’t fork");
	else if (pid != 0) /* parent */
		exit(0);
	/*
	* Change the current working directory to the root so
	* we won’t prevent file systems from being unmounted.
	*/
	if (chdir("/") < 0)
		err_quit("Can’t change directory to /");
	/*
	* Close all open file descriptors.
	*/
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i = 0; i < (int)rl.rlim_max; i++)
		close(i);
	/*
	* Attach file descriptors 0, 1, and 2 to /dev/null.
	*/
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);
	/*
	* Initialize the log file.
	*/
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d",	fd0, fd1, fd2);
		exit(1);
	}
	time(&cur_time);
	syslog(LOG_INFO, "testd daemon started at %s", ctime(&cur_time));
}

/*
pmj@PMJLaptop:~/prg/13_chap$ sudo service rsyslog status
 * rsyslogd is not running

pmj@PMJLaptop:~/prg/13_chap$ sudo service rsyslog start
 * Starting enhanced syslogd rsyslogd      [ OK ]

pmj@PMJLaptop:~/prg/13_chap$ ./a.out

pmj@PMJLaptop:~/prg/13_chap$ ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0    892   544 ?        Sl   05:37   0:00 /init
root         9  0.0  0.0    900    76 ?        Ss   05:38   0:00 /init
root        10  0.0  0.0    900    84 ?        R    05:38   0:01 /init
pmj         11  0.0  0.0  22064  5996 pts/0    Ss   05:38   0:01 -bash
syslog     597  0.0  0.0 224352  5632 ?        Ssl  06:24   0:00 /usr/sbin/rsyslogd
pmj        607  0.0  0.0   2496    76 ?        S    06:25   0:00 ./a.out
pmj        609  0.0  0.0  21852  3260 pts/0    R+   06:25   0:00 ps aux

pmj@PMJLaptop:~/prg/13_chap$ tail -2 /var/log/syslog
Feb  5 06:25:07 PMJLaptop testd: testd daemon started at Fri Feb  5 06:25:07 2021
Feb  5 06:25:26 PMJLaptop kernel: [ 2853.966073] WSL2: Performing memory compaction.

*/

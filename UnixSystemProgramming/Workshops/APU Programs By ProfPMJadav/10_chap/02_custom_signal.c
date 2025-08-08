#include "../pmj.h"

/* 
	To view signal numbers and its symbolic names:

	/usr/include/x86_64-linux-gnu/bits/signum-generic.h
*/

/*
	Run the program in the background and then send that process
	a signal using kill command:

	$ ./a.out &
	<pid>
	$ kill -USR1 <pid>
	$ kill -USR2 <pid>
	$ kill <pid>
*/

void sig_usr(int);	/* one handler for both SIGUSR1 and SIGUSR2 signals */

int main()
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_quit("can't catch SIGUSR1");

	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_quit("can't catch SIGUSR2");

	for( ; ; )
		pause(); /* wait for a signal*/
}

void sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("Received signal SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("Received signal SIGUSR2\n");
	else
		printf("Received signal %d\n", signo);
}


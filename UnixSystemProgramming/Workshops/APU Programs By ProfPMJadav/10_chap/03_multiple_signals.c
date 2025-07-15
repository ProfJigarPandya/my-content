#include "../pmj.h"

void sig_usr(int);	/* signal handler for signals SIGALRM and SIGUSR1 */

int main()
{
	if (signal(SIGALRM, sig_usr) == SIG_ERR)
		err_quit("can't catch SIGALRM");

	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_quit("can't catch SIGUSR1");
	
	alarm(2);	/* Schedule alarm for 2 seconds */
	alarm(5);	/* Cancel the previously set alarm and schedule alarm for 5 seconds */
	// alarm(0);	// Cancel the previously set alarm.

	raise(SIGUSR1);	/* send SIGUSR1 signal to process itself */

	for( ; ; )
		pause(); /* wait for a signal */
}

void sig_usr(int signo)
{
	static int counter=0;

	if (signo == SIGALRM) {
		printf("\nReceived signal SIGALRM\n");
		if (++counter != 5)
			alarm(5);
	}
	else if (signo == SIGUSR1)
		printf("\nReceived signal SIGUSR1\n");
	else
		printf("Received signal %d\n", signo);
}


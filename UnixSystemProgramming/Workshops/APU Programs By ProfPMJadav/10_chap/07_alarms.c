#include "../pmj.h"

void sig_alrm(int);

int main(void)
{
	int n;

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_quit("signal(SIGALRM, sig_alrm) error");

	alarm(5);
	n = alarm(10);
	printf("\nalarm(5), n = alarm(10), n = %d\n", n);
	alarm(0);	// Cancel the previously set alarm.


	alarm(15);
	n = alarm(10);
	printf("\nalarm(15), n = alarm(10), n = %d\n", n);
	alarm(0);	// Cancel the previously set alarm.
	
	alarm(15);
	sleep(3);
	n = alarm(10);
	printf("\nalarm(15), sleep(3), n = alarm(10), n = %d\n", n);
	alarm(0);	// Cancel the previously set alarm.
	
	alarm(3);
	pause();	// Suspend the calling process until signal is caught.
	n = alarm(10);
	printf("\nalarm(3), pause(), n = alarm(10), n = %d\n", n);
	alarm(0);	// Cancel the previously set alarm.
}

void sig_alrm(int signo)
{
	if (signo == SIGALRM) 
		printf("\nAlarm signal received.\n");
	else
		printf("\n Signal %d received.\n", signo);
}


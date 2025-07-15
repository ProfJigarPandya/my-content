#include "../pmj.h"

void sig_alrm(int);

int main(void)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_quit("Can't catch SIGALRM");

	alarm(10);	// Set an alarm for 10 seconds. 
				// Default action for an alarm signal is "terminate".

	printf("\nI am going to sleep.\n");

	pause();	// Sleep.

	printf("\nGood morning!!\n");
}

void sig_alrm(int signo)
{
	if (signo == SIGALRM)
		printf("\n\aIt's tea time. Please wake up..\n");	
}


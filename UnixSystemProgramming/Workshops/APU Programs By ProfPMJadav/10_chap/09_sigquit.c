#include "../pmj.h"

/*
	SIGQUIT signal can be generated from the terminal
	and send to the foreground process via a keyboard 
	key combination Ctrl + \
*/

void sig_quit(int);

int main(void)
{
	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_quit("Can't catch SIGQUIT");

	printf("\nI am going to sleep.\n");
	printf("\nWake me up by pressing \" Ctrl + \\ \" key combination.\n");

	pause();	// Sleep.

	printf("\nGood Morning!!\n");
}

void sig_quit(int signo)
{
	if (signo == SIGQUIT)
		printf("\nSignal SIGQUIT received.\n");	
}


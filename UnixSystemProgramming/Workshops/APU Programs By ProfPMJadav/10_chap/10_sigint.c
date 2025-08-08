#include "../pmj.h"

/*
	SIGINT signal can be generated from the terminal
	and send to the foreground process via a keyboard 
	key combination Ctrl + C
*/

void sig_int(int);

int main(void)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_quit("Can't catch SIGINT");

	printf("\nI am going to sleep.\n");
	printf("\nWake me up by pressing \" Ctrl + C \" key combination.\n");

	pause();	// Sleep.

	printf("\nGood Morning!!\n");
}

void sig_int(int signo)
{
	if (signo == SIGINT)
		printf("\nSignal SIGINT received.\n");	
}


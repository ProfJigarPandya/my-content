#include "../pmj.h"

static void sig_quit(int);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;
	
	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_quit("can’t catch SIGQUIT");

	/* Block SIGQUIT and save current signal mask.	*/
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_quit("SIG_BLOCK error");
	
	printf("\nSend SIGQUIT signal by pressing Ctrl + \\ \n");
	sleep(5); /* SIGQUIT here will remain pending */
	if (sigpending(&pendmask) < 0)
		err_quit("sigpending error");
	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");
	
	/* Restore signal mask which unblocks SIGQUIT.	*/
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_quit("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");
	sleep(5); /* SIGQUIT here will terminate with core file */
	exit(0);
}
static void sig_quit(int signo)
{
	if (signo == SIGQUIT) {
		printf("caught SIGQUIT\n");
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			err_quit("can’t reset SIGQUIT");
	}
}
/*
pmj@PMJLaptop:~/prg/10_chap$ ./a.out

Send SIGQUIT signal by pressing Ctrl + \
^\											generate signal once (before 5 seconds are up)
SIGQUIT pending								after return from sleep
caught SIGQUIT								in signal handler
SIGQUIT unblocked							after return from sigprocmask
^\Quit										generate signal again

pmj@PMJLaptop:~/prg/10_chap$ ./a.out

Send SIGQUIT signal by pressing Ctrl + \
^\^\^\^\^\^\^\								generate signal multiple times (before 5 seconds are up)
SIGQUIT pending								
caught SIGQUIT								signal is generated only once!!!!!
SIGQUIT unblocked							
^\Quit										generate signal again

*/


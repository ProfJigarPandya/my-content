#include "../pmj.h"

/*
  struct sigaction {
      void     (*sa_handler)(int);
      void     (*sa_sigaction)(int, siginfo_t *, void *);
      sigset_t   sa_mask;
      int        sa_flags;
      void     (*sa_restorer)(void);
  };
*/

void sig_alrm( int signo ) {
	if (signo == SIGALRM)
	    printf( "Signal SIGALRM received.\n" );
}

int main(void) {
    struct sigaction sact;

    sact.sa_flags = 0;
    sact.sa_handler = sig_alrm;	/* Setup the signal handler. */
	sigemptyset(&sact.sa_mask);	/* Unblock all the signals. */

    if ( sigaction( SIGALRM, &sact, NULL ) == -1 )
		err_quit("sigaction(SIGALRM) error");

    alarm(2);     /* SIGALRM will be sent in 2 second */

	printf("\nI am going to sleep.\n");
	pause();	/* Suspend the process until signal is caught */
	printf("\nI am awake.\n");

	printf("\n Goodbye!! \n");
    return( 0 );
}



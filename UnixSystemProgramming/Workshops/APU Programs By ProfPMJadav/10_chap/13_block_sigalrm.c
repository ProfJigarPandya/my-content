#include "../pmj.h"

void sig_alrm( int signo ) {
	if (signo == SIGALRM)
	    printf( "Signal SIGALRM received.\n" );
}

int main(void) {
    time_t start, finish;
	char reply;
    struct sigaction sact;
    sigset_t new_set, old_set;
    //double diff;

    sigemptyset( &sact.sa_mask );
    sact.sa_flags = 0;
    sact.sa_handler = sig_alrm;
    sigaction( SIGALRM, &sact, NULL );

    sigemptyset( &new_set );
    sigaddset( &new_set, SIGALRM );
	
	printf("Do you want to block SIGALRM? ");
	scanf("%c", &reply);
	if (reply == 'y' || reply == 'Y')
	    sigprocmask( SIG_BLOCK, &new_set, &old_set);

    time( &start );
    printf( "SIGALRM signals blocked at %s\n", ctime(&start) );

    alarm(2);     /* SIGALRM will be sent in 2 second */

	sleep(5);	

    time( &finish );
    //diff = difftime( finish, start );

	if (reply != 'y' || reply != 'Y')
	    sigprocmask( SIG_SETMASK, &old_set, NULL );
    printf( "SIGALRM signals unblocked at %s\n", ctime(&finish) );

    return( 0 );
}



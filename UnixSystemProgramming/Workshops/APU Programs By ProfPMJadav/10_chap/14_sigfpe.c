#include "../pmj.h"

void sig_fpe(int signo)
{
	if (signo == SIGFPE) {
		printf("\nSignal SIGFPE received.\n");
		exit(1);
	}
}
int gen_fpe() {
	int x = 0 ;
	return 1 % x ;
}
int main ( ) 
{
	struct sigaction sa; 
	
	sa.sa_handler = sig_fpe;
	sa.sa_flags = 0 ;
	sigemptyset(&sa.sa_mask) ;
	
	sigaction(SIGFPE, &sa , NULL) ;

	gen_fpe() ;

	printf("\nGoodbye!!\n");
	return ( 0 ) ;
}


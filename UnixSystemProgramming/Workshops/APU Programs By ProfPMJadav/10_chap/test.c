#include "../pmj.h"

jmp_buf fpe;

void handler(int signo)
{
    // Do stuff here then return to execution below
    if (signo == SIGFPE)
		longjmp(fpe, 1);
}

int main()
{
    volatile int i, j;
	int zero = 0;

    for(i = 0; i < 10; i++) 
    {
        // Call signal handler for SIGFPE
        struct sigaction act;
        struct sigaction oldact;
        
		act.sa_handler = handler;
        act.sa_flags = SA_NODEFER | SA_NOMASK;
        sigaction(SIGFPE, &act, &oldact);

        if (0 == setjmp(fpe))
        {
            j = i / zero;
        } else {
            sigaction(SIGFPE, &oldact, &act);
            /* handle SIGFPE */
        }
    }

    printf("After for loop j = %d", j);

    return 0;
}



#include "../pmj.h"


int main(void)
{

	alarm(10);		// Set an alarm for 10 seconds. 
					// Default action for an alarm signal is "terminate".

	// alarm(0);	// Cancel the previously set alarm.

	printf("\nI am going to sleep.\n");

	pause();		// Sleep until receipt of a signal.

	// sleep(5);	// Sleep for 5 seconds.

	printf("\nGood morning!!\n");
}



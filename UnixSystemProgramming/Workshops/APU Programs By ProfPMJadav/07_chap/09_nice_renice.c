#include "../pmj.h"

/*
Use of nice and renice command.

$ nice --adjustment=5 ./a.out &			// Run a.out with priority 5
<pid>

$ top									// To view the priority of the process

$ renice -n 10 <pid>					// Decrease the priority of the process

$ sudo renice -10 <pid>					// Increase the priorit of the process as root

$ kill -9 <pid>							// Kill the process
*/

int main()
{
	pause(); // wait for signal
}


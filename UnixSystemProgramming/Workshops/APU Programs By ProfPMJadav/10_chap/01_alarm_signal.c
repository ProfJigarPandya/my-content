#include "../pmj.h"
/*
	Run the process in the background and then send the alarm and kill signal:

	$ man 7 signal
	$ kill -l
	$ ./a.out &
	<pid>
	$ kill -STOP <pid>			// Sends the SIGSTOP signal to the process
	$ kill -CONT <pid>			// Sends the SIGCONT signal to the process
	$ kill -ALRM <pid>			// Sends the SIGALRM signal to the process
	$ kill -INT  <pid>			// Sends the SIGINT  signal to the process
	$ kill -s SIGALRM <pid>		// Another way to send the SIGALRM signal to the process
	$ ulimit -c					// To see the current core dump limit.
	$ ulimit -c unlimited		// To set the core dump limit to unlimited.
	$ kill -ABRT <pid>			// Default action (i.e. terminate + core) will be taken.
	$ file core					// Check the file type of "core" file.
	$ readelf -Wa core			// Get information from the core file.
	$ man 5 core				// Manual page for "core" file
	$ ps aux					// To check the process terminated and generated the core dump.
	$ gdb a.out core			// To view the location in the source code, due to which core dump was generated.
*/

void sig_usr(int);	/* signal handler for SIGALRM */

int main()
{
	if (signal(SIGALRM, sig_usr) == SIG_ERR) // Catch the SIGALRM signal
		err_quit("can't catch SIGALRM");

	if (signal(SIGINT, SIG_IGN) == SIG_ERR)	// Ignore the SIGINT signal
		err_quit("Can't ignore SIGINT");

	for( ; ; )
		pause(); /* wait for a signal*/
}

void sig_usr(int signo)
{
	if (signo == SIGALRM)
		printf("Received signal SIGALRM\n");
	else
		printf("Received signal %d\n", signo);
}


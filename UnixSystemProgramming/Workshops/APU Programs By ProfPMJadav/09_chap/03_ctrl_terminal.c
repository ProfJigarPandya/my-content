#include "../pmj.h"

/*
	• A session can have a single controlling terminal. 
		This is usually the terminal device (in the case
		 of a terminal login) or pseudo terminal device
		 (in the case of a network login) on which we log in.

	• The session leader that establishes the connection
		 to the controlling terminal is called the controlling
		 process.

	• The process groups within a session can be divided
		 into a single foreground process group and one or
		 more background process groups.

	• If a session has a controlling terminal, it has a
		 single foreground process group and all other process
		 groups in the session are background process groups.

	• Whenever we press the terminal’s interrupt key 
		(often DELETE or Control-C), the interrupt signal is 
		sent to all processes in the foreground process group.

	• Whenever we press the terminal’s quit key 
		(often Control-backslash), the quit signal is sent to
		 all processes in the foreground process group.

	• If a modem (or network) disconnect is detected by
		 the terminal interface, the hang-up signal is sent 
		to the controlling process (the session leader).

	Usually, we don’t have to worry about the controlling 
	terminal; it is established automatically when we log in.

	There are times when a program wants to talk to the 
	controlling terminal, regardless of whether the standard
	input or standard output is redirected.

	The way a program guarantees that it is talking to 
	the controlling terminal is to open the file /dev/tty.
	This special file is a synonym within the kernel for 
	the controlling terminal. Naturally, if the program 
	doesn’t have a controlling terminal, the open of this
	device will fail.
		$ cat abc.txt > /dev/tty
		$ cat < /dev/tty
*/

int main(void)
{
	printf("\nControlling Terminal\n");
	return 0;
}


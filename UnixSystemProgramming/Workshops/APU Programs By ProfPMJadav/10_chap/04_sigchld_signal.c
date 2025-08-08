#include "../pmj.h"

/*
	Process should wait for the child to terminate and get its
	exit status code using wait()/waitpid() systemcall. 

	If parent is not waiting then if one of the child terminate 
	it will	receive SIGCHLD signal. In this case the child process 
	will become zombie until the parent calls wait()/waitpid(). 
	Also the parent will not be able to get the correct exit status 
	code of the child. But parent can call wait()/waitpid() in
	the signal handler of SIGCHLD to remove the zombie children 
	processes from the process table.
*/
void sig_usr(int);	/* signal handler for SIGCHLD */

int main()
{
	if (signal(SIGCHLD, sig_usr) == SIG_ERR)
		err_quit("can't catch SIGCHLD");

	unlink("output.txt");
	if (fork() > 0) { // parent
		if (fork() > 0) {	// parent
			if (fork() > 0) {	//parent
				pause();
				pause();
				pause();
				return 0;
			}
			else {	// child
				sleep(15);
				return 3;
			}
		}
		else {	//child
			sleep(10);
			return 2;
		}
	} else {	//child
		sleep(5);
		return 1;
	}
}

void sig_usr(int signo)
{
	int pid, status;

	if (signo == SIGCHLD) {
		pid = wait(&status);
		printf("\npid %d terminated.\n", pid);
	}
}


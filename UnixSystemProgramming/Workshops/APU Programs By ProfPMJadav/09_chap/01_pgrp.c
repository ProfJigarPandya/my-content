#include "../pmj.h"

/*
	 1) If pid=pgid Then process is group leader.
	 2) Process can change the pgid of itself or any of its 
	   childern but not after child does exec().
	 3) Use following command to terminate all the processes
		of the same process group:
			kill -9 <-pgid>
	 4) A Session is a collection of one or more process groups.	
*/

void procinfo()
{
	printf("Process information:\n");
	printf("pid =  %d, ppid = %d, pgid = %d, sid = %d\n", 
			getpid(), getppid(), getpgrp(), getsid(0));
}
int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0) {	//child
		pid = getpid();
		procinfo();
		printf("Child: I am going to become process leader\n");
		setpgid(pid, pid);	//set itself process leader
		procinfo();
	} else {	// parent
		procinfo();
		printf("Parent: I am going to make child as process leader\n");
		setpgid(pid, pid);
	}
	pause();
	return 0;
}


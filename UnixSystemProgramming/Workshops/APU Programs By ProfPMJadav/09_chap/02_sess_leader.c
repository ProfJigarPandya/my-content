#include "../pmj.h"

/*
	pid_t setsid(void);

	If the calling process is not a process group leader, 
	this function creates a new session.
	
	Three things happen.
	1. The process becomes the session leader of this new 
		session. (A session leader is the process that 
		creates a session.) The process is the only process 
		in this new session.
	2. The process becomes the process group leader of 
		a new process group. The new process group ID is 
		the process ID of the calling process.
	3. The process has no controlling terminal. 
		If the process had a controlling terminal before 
		calling setsid, that association is broken.

	This function returns an error if the caller is 
	already a process group leader.

	Process State = Ss means the process is sleeping 
	and is a session leader.
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
		procinfo();
		printf("Session leader of %d is %d\n", getpid(), getsid(0));
		printf("Child: I am going to become session leader\n");
		setsid();	//set itself session leader
		procinfo();
	} else {	// parent
		procinfo();
	}
	pause();
	return 0;
}
/*
pmj@PMJLaptop:~/prg/09_chap$ ./a.out &
[1] 308

pmj@PMJLaptop:~/prg/09_chap$ Process information:
pid =  308, ppid = 11, pgid = 308, sid = 11
Process information:
pid =  309, ppid = 308, pgid = 308, sid = 11
Child: I am going to become session leader
Process information:
pid =  309, ppid = 308, pgid = 309, sid = 309

pmj@PMJLaptop:~/prg/09_chap$ ps ajx
 PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    0     1     0     0 ?           -1 Sl       0   0:00 /init
    1     9     9     9 ?           -1 Ss       0   0:00 /init
    9    10     9     9 ?           -1 S        0   0:01 /init
   10    11    11    11 pts/0      310 Ss    1000   0:00 -bash
   11   308   308    11 pts/0      310 S     1000   0:00 ./a.out
  308   309   309   309 ?           -1 Ss    1000   0:00 ./a.out
   11   310   310    11 pts/0      310 R+    1000   0:00 ps ajx

*/

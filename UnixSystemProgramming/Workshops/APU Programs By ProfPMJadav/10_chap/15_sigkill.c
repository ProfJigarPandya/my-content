#include "../pmj.h"

int main(void)
{
	pid_t pid;

	pid = fork();
	
	if (pid < 0)
		err_quit("fork() error");

	if (pid == 0) {	// child
		kill (getppid(), SIGSTOP);
		printf("\nI am child with pid = %d\n", getpid());
		printf("\nI have stopped parent process (%d)\n", getppid());
	}
	else {	// parent
		kill (pid, SIGSTOP);
		printf("\nI am parent with pid = %d\n", getpid());
		printf("\nI have stopped child process (%d)\n", pid);
	}
	pause();
	return 0;
}
/*
pmj@PMJLaptop:~/prg/10_chap$ ./a.out &
[1] 571

pmj@PMJLaptop:~/prg/10_chap$
I am parent with pid = 571

I have stopped child process (572)

pmj@PMJLaptop:~/prg/10_chap$ ps ajx
 PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    0     1     0     0 ?           -1 Sl       0   0:00 /init
    1    63    63    63 ?           -1 Ss       0   0:00 /init
   63    64    63    63 ?           -1 S        0   0:01 /init
   64    65    65    65 pts/1      574 Ss    1000   0:01 -bash
   65   571   571    65 pts/1      574 S     1000   0:00 ./a.out
  571   572   571    65 pts/1      574 T     1000   0:00 ./a.out
   65   574   574    65 pts/1      574 R+    1000   0:00 ps ajx
pmj@PMJLaptop:~/prg/10_chap$ kill -CONT 572

pmj@PMJLaptop:~/prg/10_chap$
I am child with pid = 572

I have stopped parent process (571)


[1]+  Stopped                 ./a.out

pmj@PMJLaptop:~/prg/10_chap$ ps ajx
 PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    0     1     0     0 ?           -1 Sl       0   0:00 /init
    1    63    63    63 ?           -1 Ss       0   0:00 /init
   63    64    63    63 ?           -1 S        0   0:01 /init
   64    65    65    65 pts/1      575 Ss    1000   0:01 -bash
   65   571   571    65 pts/1      575 T     1000   0:00 ./a.out
  571   572   571    65 pts/1      575 S     1000   0:00 ./a.out
   65   575   575    65 pts/1      575 R+    1000   0:00 ps ajx

pmj@PMJLaptop:~/prg/10_chap$ kill -CONT 571

pmj@PMJLaptop:~/prg/10_chap$ ps ajx
 PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    0     1     0     0 ?           -1 Sl       0   0:00 /init
    1    63    63    63 ?           -1 Ss       0   0:00 /init
   63    64    63    63 ?           -1 S        0   0:01 /init
   64    65    65    65 pts/1      576 Ss    1000   0:01 -bash
   65   571   571    65 pts/1      576 S     1000   0:00 ./a.out
  571   572   571    65 pts/1      576 S     1000   0:00 ./a.out
   65   576   576    65 pts/1      576 R+    1000   0:00 ps ajx

pmj@PMJLaptop:~/prg/10_chap$ kill 571 572

pmj@PMJLaptop:~/prg/10_chap$ ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0    892   552 ?        Sl   08:51   0:00 /init
root        63  0.0  0.0    900    84 ?        Ss   09:10   0:00 /init
root        64  0.0  0.0    900    92 ?        S    09:10   0:01 /init
pmj         65  0.0  0.0  22448  6392 pts/1    Ss   09:10   0:01 -bash
pmj        577  0.0  0.0  21852  3316 pts/1    R+   11:36   0:00 ps aux
[1]+  Terminated              ./a.out

*/

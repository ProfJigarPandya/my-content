#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sighandlerAlarm(int signo);
int main()
{
	printf("\n Demo of an alarm signal ");

	signal(SIGALRM,sighandlerAlarm);//kill -l | grep SIGALRM   
//14) SIGALRM
	alarm(15);//may comment this and send signal from other terminal using  kill -14
pause();
printf("\n Have a nice day!");
}

void sighandlerAlarm(int signo)
{
	printf("\n Alarm buzzing now ");

}

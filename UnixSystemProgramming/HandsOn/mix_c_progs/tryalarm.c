#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sighandlerAlarm(int signo);
int main()
{
	printf("\n Demo of an alarm signal ");

	signal(SIGALRM,sighandlerAlarm);
	alarm(30);
	while(1);	
}

void sighandlerAlarm(int signo)
{
	printf("\n Alarm buzzing now ");

}

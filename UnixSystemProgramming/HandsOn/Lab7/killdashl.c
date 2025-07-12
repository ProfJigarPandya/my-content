#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

extern int errno;
extern const char *const sys_siglist[];

int main()
{
	int i;
	char buff[256]="Signal Msg";
	printf("\n SigNo.\t SigCode \t SigDesciption ");
	for(i=1;i<32;i++)
	{
		printf("\n%d\t%s",i,sys_siglist[i]);
	}
	for(i=1;i<32;i++)
	{
		sprintf(buff,"SigNo %d :",i);
		psignal(i,buff);
	}
	for(i=1;i<32;i++)
	{
		printf("\n%d\t%s",i,strsignal(i));
	}
}

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("\n %s <pid> ",argv[0]);
		exit(1);
	}
	printf("\n Press any key to demo \"SIGSTOP\"");
	getchar();
	kill(atoi(argv[1]),SIGSTOP);// -SIGSTOP 3814
	
	printf("\n Press any key to demo \"SIGCONT\"");
	getchar();
	kill(atoi(argv[1]),SIGCONT);// -SIGCONT 3814

}


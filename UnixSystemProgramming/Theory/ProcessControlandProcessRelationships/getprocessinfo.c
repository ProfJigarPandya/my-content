#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("\n Hello World!. Demonstrating userid and effective user id");
	printf("\n getpid() %d ",getpid());
	printf("\n getppid() %d ",getppid());
	printf("\n getuid() %d ",getuid());
	printf("\n geteuid() %d ",geteuid());
	printf("\n getgid() %d ",getgid());
	printf("\n getegid() %d ",getegid());
	return(0);
}

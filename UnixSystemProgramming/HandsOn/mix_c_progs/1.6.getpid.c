#include <unistd.h>
#include <stdio.h>

int main()
{
	printf(" Hello World from process ID %d\n", getpid());
	printf(" Press any key to continue. ");
	getchar();
	return(0);
}

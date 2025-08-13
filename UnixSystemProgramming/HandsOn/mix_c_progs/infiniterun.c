#include <stdio.h>
#include <string.h>
//To demonstrate core dump and SIGSTOP-SIGCONT
//ulimit -c unlimited
//vi /cores/core.processid

int main()
{
	int i;
	for(;;)
	{
		printf("\n %d \n",i);
		i++;
	}
}

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

extern int errno;

int main()
{
	long st;
	st = sysconf(_SC_OPEN_MAX);
	if(st == -1)
	{
		printf("\n Name is invalid: %s",strerror(errno));
	}
	else
	{
		printf("Returned val is %ld",st);
	}
	return 0;
}

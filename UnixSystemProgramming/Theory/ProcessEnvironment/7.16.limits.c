#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define doit(name) pr_limits(#name,name)

extern int errno;

static void pr_limits(char *name, int resource);
int main()
{
	
	doit(RLIMIT_NOFILE);
	return(0);
}
static void pr_limits(char *name, int resource)
{
	struct rlimit limit;
	if(getrlimit(resource, &limit)<0)
	{
		printf("\n Error getrlimit %s ",strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("\n\n %s",name);
	if(limit.rlim_cur == RLIM_INFINITY)
		printf("\n infinite ");
	else
		printf("\n%10llu",limit.rlim_cur);
	
	if(limit.rlim_max == RLIM_INFINITY)
		printf("\n infinite ");
	else
		printf("\n%10llu",limit.rlim_max);
}

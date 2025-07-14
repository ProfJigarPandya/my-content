#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#define MAX 256
extern int errno;

int main()
{
	struct utsname name;
	char hname[MAX];
	if((uname(&name)==-1))
	{
		printf("\n Error in uname %s ",strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("%s\n",name.sysname);//       Name of the operating system implementation.

        printf("%s\n",name.nodename);//      Network name of this machine.

        printf("%s\n",name.release);//       Release level of the operating system.

        printf("%s\n",name.version);//       Version level of the operating system.

        printf("%s\n",name.machine);//       Machine hardware platform.
	
	if((gethostname(hname,MAX)==-1))
	{
		printf("\n Error in gethostname %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("Hostname %s \n",hname);
	return(0);
}

/* Demo program to explain the proc filesystem and purpose.
 * MacOS X has sysctl -a command.
 *
 * for i in {1..6000}; do echo "$i" >> $i; done;
 * cat /proc/`pgrep a.out`/limits
 * prlimit --pid xxxxx --nofile=3024:4095

   for i in {1..6000}; do rm -rf $i; done;


 */

/*
man ulimit

 A hard limit cannot be  increased
              by  a non-root user once it is set; a soft limit may be increased up to the value of
              the hard limit.

       struct rlimit {
           rlim_t  rlim_cur;  /* Soft limit */
           rlim_t  rlim_max;  /* Hard limit (ceiling for rlim_cur) */
       };

       typedef /* ... */  rlim_t;  /* Unsigned integer type */



man prlimit
prlimit - get and set process resource limits



*/


#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>

extern int errno;
int main()
{
	int i;
	FILE *fp;
	char fname[10];
	for(i=0;i<5500;i++)
	{
		sprintf(fname, "%d", i);
		printf("\n Opening file %s" ,fname);
		fp = fopen(fname,"r");
		if(fp == NULL)
		{
			printf("\n\t %s\n Press key to move on. ",strerror(errno));
			getchar();
		}
	}
}

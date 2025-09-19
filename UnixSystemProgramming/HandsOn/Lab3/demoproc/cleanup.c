/* Demo program to explain the proc filesystem and purpose.
 * MacOS X has sysctl -a command.
 *
 * for i in {1..6000}; do echo "$i" >> $i; done;
 * cat /proc/`pgrep a.out`/limits
 * prlimit --pid xxxxx --nofile=3024:4095
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


extern int errno;
int main()
{
	int i;
	int sta=-1;
	char fname[10];
	for(i=1;i<=6000;i++)
	{
		sprintf(fname, "%d", i);
		printf("\n Opening file %s" ,fname);
		sta=unlink(fname);
		if(sta == -1)
		{
			printf("\n\t %s\n Press key to move on. ",strerror(errno));
			//getchar();
		}
	}
}

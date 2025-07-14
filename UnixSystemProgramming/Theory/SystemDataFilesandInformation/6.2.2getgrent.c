#include <stdio.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <grp.h>
#include <uuid/uuid.h>


int main(int argc, char *argv[])
{

	struct group *grp;
	char *ptr;
	int i;
       	setgrent();

	while((grp=getgrent()))
	{
		printf("\n%s\t",grp->gr_name);
		printf("%s\t",grp->gr_passwd);

                printf("%d\t",grp->gr_gid);         /* gid */
		i=0;
		printf("List of members: ");
		while( (ptr = *((grp->gr_mem)+i)) )
		{
			printf("%s,",ptr);
			i++;
		}
	}

       	endgrent();
	
	return(EXIT_SUCCESS);
}

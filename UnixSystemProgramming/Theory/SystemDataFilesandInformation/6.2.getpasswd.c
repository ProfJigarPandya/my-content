#include <stdio.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{

	struct passwd *psw;

       	setpwent();

	while((psw=getpwent()))
	{
		printf("\n%s\t",psw->pw_name);
		printf("%s\t",psw->pw_passwd);

                printf("%d\t",psw->pw_uid);         /* user uid */
                printf("%d\t",psw->pw_gid);         /* user gid */
                //   time_t  pw_change;      /* password change time */
                //   char    *pw_class;      /* user access class */
                //   char    *pw_gecos;      /* Honeywell login info */
                printf("%s\t",psw->pw_dir);        /* home directory */
                //   char    *pw_shell;      /* default shell */
                //   time_t  pw_expire;      /* account expiration */
                //   int     pw_fields;

	}

       	endpwent();
	
	return(EXIT_SUCCESS);
}

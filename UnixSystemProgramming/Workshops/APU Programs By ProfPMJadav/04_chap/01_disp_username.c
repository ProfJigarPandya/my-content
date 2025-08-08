#include "../pmj.h"
/*
struct passwd {
               char   *pw_name;      
               char   *pw_passwd;   
               uid_t   pw_uid;     
               gid_t   pw_gid;    
               char   *pw_gecos; 
               char   *pw_dir;  
               char   *pw_shell;
           };
*/
int main()
{
	struct passwd *userinfo;

	userinfo = getpwuid(getuid());

	if (userinfo == NULL)
		err_quit("getpwuid");

	printf("Logged in user is      : %s\n", userinfo->pw_name);
	printf("Home dir of the user   : %s\n", userinfo->pw_dir);
	printf("Logged in user's shell : %s\n", userinfo->pw_shell);

	return 0;
}


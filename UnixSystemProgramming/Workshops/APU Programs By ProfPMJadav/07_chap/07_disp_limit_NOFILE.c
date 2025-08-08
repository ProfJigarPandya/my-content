#include "../pmj.h"

/*
struct rlimit {
	rlim_t rlim_cur; // soft limit: current limit 
	rlim_t rlim_max; // hard limit: maximum value for rlim_cur
};
*/
int main()
{
 	struct rlimit limit;
  	unsigned long long lim;

  	if (getrlimit (RLIMIT_NOFILE, &limit) < 0)
    	err_quit ("getrlimit");
	
	printf ("RLIMIT_NOFILE : ");

  	if (limit.rlim_cur == RLIM_INFINITY)
      	printf ("(infinite) ");
  	else  {
     	lim = limit.rlim_cur;
      	printf ("%10lld ", lim);
  	}

  	if (limit.rlim_max == RLIM_INFINITY)
    	printf ("(infinite)");
  	else {
      	lim = limit.rlim_max;
      	printf ("%10lld", lim);
  	}
  	printf("\n");

  	exit(EXIT_SUCCESS);
}


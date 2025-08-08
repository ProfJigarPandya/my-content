#include <stdio.h>
#include <stdlib.h>

long bin_date (void);
char *str_date (long bintime);
int
main (int argc, char **argv)
{
  long lresult;			/* return from bin_date */
  char *sresult;		/* return from str_date */
  if (argc != 1)
    {
      fprintf (stderr, "usage: %s\n", argv[0]);
      exit (1);
    }
/* call the procedure bin_date */
  lresult = bin_date ();
  printf ("time is %ld\n", lresult);
/* convert the result to a date string */
  sresult = str_date (lresult);
  printf ("date is %s", sresult);
}				/* main */

/* bin_date returns the system time in binary format */
long
bin_date (void)
{
  long timeval;
  long time ();			/* Unix time 
				   function; returns time */
  timeval = time ((long *) 0);
  return timeval;
}				/* bin_date */

/* str_date converts a binary time into a date string */
char *
str_date (long bintime)
{
  char *ptr;
  char *ctime ();		/* Unix library 
				   function that does the work */
  ptr = ctime (&bintime);
  return ptr;
}				/* str_date */

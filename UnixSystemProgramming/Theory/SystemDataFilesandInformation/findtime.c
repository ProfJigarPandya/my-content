#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
/*

man 2 time
     struct timeval {
               time_t      tv_sec;     // seconds 
               suseconds_t tv_usec;    // microseconds 
           };

       and gives the number of seconds and microseconds since the Epoch (see time(2)).  The tz argument is a struct timezone:

           struct timezone {
               int tz_minuteswest;     // minutes west of Greenwich 
               int tz_dsttime;         // type of DST correction 
           };



man 3 gmtime
   Broken-down time is stored in the structure tm, which is defined in <time.h> as follows:

           struct tm {
               int tm_sec;    // Seconds (0-60) 
               int tm_min;    // Minutes (0-59) 
               int tm_hour;   // Hours (0-23) 
               int tm_mday;   // Day of the month (1-31) 
               int tm_mon;    // Month (0-11) 
               int tm_year;   // Year - 1900 
               int tm_wday;   // Day of the week (0-6, Sunday = 0) 
               int tm_yday;   // Day in the year (0-365, 1 Jan = 0) 
               int tm_isdst;  // Daylight saving time 
           };


Functions ctime, localtime, mktime, strftime are all affected by the TZ environment variable.


Below functions give us string

ctime (input is time_t calendar time datatype from kernel time api)
asctime (input is struct tm broken down time datatype)


Formatted String
strftime (inut is struct tm broken down time datatype)

*/

#define MAX 256
extern int errno;

int main()
{	
	time_t t; //From kernel. Calendar Time.
	struct timeval tp;//seconds and microseconds .. more precision
	struct tm *bdt;//brokendowntime;
	size_t sizeofdt;
	char buff[MAX];
	if(time(&t)==-1)//system call... Get time in seconds only since epoch
	{
		printf("Error in retriving time. %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("time api: \n Seconds %ld since epoch\n",t);//
	
	
	
	gettimeofday(&tp,NULL);//provides greater resolution. i.e. upto microsecond. System call  time as well as a timezone	
	printf("gettimeofday api: \n (Seconds %ld and microseconds %d) since epoch ",tp.tv_sec, tp.tv_usec);

	bdt = gmtime(&(tp.tv_sec));//c library function
	printf("\n Broken Down Time using tm structure \n");
	printf("\nSeconds %d",bdt->tm_sec);     /* seconds (0 - 60) */
        printf("\nMinutes %d",bdt->tm_min);     /* minutes (0 - 59) */
        printf("\nHours %d",bdt->tm_hour);    /* hours (0 - 23) */
        printf("\nDay of month %d",bdt->tm_mday);    /* day of month (1 - 31) */
        printf("\nMonth of year %d",bdt->tm_mon);     /* month of year (0 - 11) */
        printf("\nYear %d. After addition %d" ,bdt->tm_year,1900+bdt->tm_year);    /* year - 1900 */
        printf("\nDay of week %d",bdt->tm_wday);    /* day of week (Sunday = 0) */
        printf("\nDay of year %d",bdt->tm_yday);    /* day of year (0 - 365) */
        printf("\nIs summer time in effect %d",bdt->tm_isdst);   /* is summer time in effect? */
        printf("\nTimezone name %s",bdt->tm_zone);  /* abbreviation of timezone name */
        printf("\nOffset from UTC in seconds %ld",bdt->tm_gmtoff); /* offset from UTC in seconds */
	
	printf("\nTime_t %ld - converted from broken down time.",mktime(bdt));//convert broken down time, a local time, converts into time_t value.

	printf("\n Date using ctime function %s ",ctime(&t));
	system("date");

	sizeofdt=strftime(buff,MAX,"%A %Y %m %T",bdt);
	
	if(sizeofdt ==0)
	{
		//printf("\n Error in formatting date using strftime %s ",strerror(errno));
		exit(EXIT_FAILURE);
	}
	//buff[sizeofdt]='\0'; not required explicitly
	printf("Formatted using strftime %s",buff);
}

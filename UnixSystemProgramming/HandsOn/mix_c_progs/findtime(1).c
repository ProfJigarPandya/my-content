#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 256
extern int errno;

int main()
{	
	time_t t;
	struct timeval tp;
	struct tm *bdt;//brokendowntime;
	size_t sizeofdt;
	char buff[MAX];
	if(time(&t)==-1)//library function
	{
		printf("Error in retriving time. %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("time api: \n Seconds %ld since epoch\n",t);
	
	
	
	gettimeofday(&tp,NULL);//provides greater resolution. i.e. upto microsecond. System call	
	printf("gettimeofday api: \n (Seconds %ld and microseconds %d) since epoch ",tp.tv_sec, tp.tv_usec);

	bdt = gmtime(&(tp.tv_sec));
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

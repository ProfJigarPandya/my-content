#include <stdio.h>
#include <time.h>

int main()
{
	time_t t;
	char buff[256];
	time(&t);
	sprintf(buff,"%s",ctime(&t));
	printf("%s",buff);
}


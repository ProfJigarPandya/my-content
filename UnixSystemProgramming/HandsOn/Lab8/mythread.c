/*

Thread creation and Termination. 
Use of pthread library functions.
Write a 'C' program on Linux platform which demonstrates the multiple threads creation and their execution.
When thread executes, it prints some hello message with thread ID as its identity.

*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 100

void* dispThreadInfo(void *p);
int g=10;
int main()
{
	pthread_t t[MAX];
	char msg[MAX];

	int ret,i,n=3;
	sprintf(msg,"Process ID %d",getpid());
	printf("\n Demo threads ");
	for(i=0;i<n && i<MAX;i++)
	{
		printf("\n Demo threads # %d",i+1);
		ret=pthread_create(&t[i],NULL,dispThreadInfo,(void*)msg);	
		if(ret) //returns 0 on success
		{
			printf("Thread creation failed with error code %d message %s\n", ret,strerror(ret));
			return (EXIT_FAILURE);
		}
	}
	
	for(i=0;i<n && i<MAX;i++)
		pthread_join( t[i], NULL);

	return(EXIT_SUCCESS);
}

void* dispThreadInfo(void *p)
{
	printf("\nHi, this is a demo thread with thread id %ld",pthread_self());//Need to know, how to print 
	printf("\n Parameters %s",p);
	strcpy((char *)p,"dummm");
	printf("\n%d",g);

}

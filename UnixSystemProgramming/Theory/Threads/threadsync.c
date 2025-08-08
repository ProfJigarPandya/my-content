//Demonstrating thread synchronization
/*
 * [jigar.pandya@localhost threadsync]$ ./threadsync.o 
 * Order 1000 increments, 2000 increments, 3000 increments.
 *
 *
 * Result by regular function in order.
 *  n1:1000, res1:1000
 *  n2:2000, res2:3000
 *  n3:3000, res3:6000
 *
 * Demonstrating NON-SYNC THREAD
 * Unsync: n1:1000, res1:1000
 * Unsync: n2:2000, res2:5305
 * Unsync: n3:3000, res3:6000
 *
 * Demonstrating SYNC THREAD
 * Safe: n1:1000, res1:1000
 * Safe: n2:2000, res2:3000
 * Safe: n3:3000, res3:6000
 *
 *
 * You may expect below also, because we have not ordered threads execution. i.e. 1000 then 2000 then 3000; For that we need create and join pairs.
 * Demonstrating SYNC THREAD
 * Safe: n1:1000, res1:4000
 * Safe: n2:2000, res2:6000
 * Safe: n3:3000, res3:3000
 *
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


extern int errno;
struct package
{
	int n;
	int res;
};

void inc(int n);
void* nonsync(void *nonspac);
void* syncc(void *synpac);

int glinc=0;
int glnonsync=0;
int glsync=0;
pthread_mutex_t mutex;

int main()
{
	
	int n1=1000, n2=2000, n3=3000;

	pthread_t nonst1,nonst2,nonst3;
	struct package nonspac1,nonspac2,nonspac3;
	nonspac1.n = n1;nonspac1.res=0;
	nonspac2.n = n2;nonspac2.res=0;
	nonspac3.n = n3;nonspac3.res=0;

	pthread_t synct1,synct2,synct3;
	struct package synpac1,synpac2,synpac3;
	synpac1.n = n1;synpac1.res=0;
	synpac2.n = n2;synpac2.res=0;
	synpac3.n = n3;synpac3.res=0;

	
	//Expected Result
	printf("\nResult by regular functions in order.\n");
	inc(n1);
	printf(" n1:%d, res1:%d\n",n1,glinc);
	inc(n2);
	printf(" n2:%d, res2:%d\n",n2,glinc);
	inc(n3);
	printf(" n3:%d, res3:%d\n",n3,glinc);
	
	//Demonstrating nonsync
	printf("\nDemonstrating NON-SYNC THREAD\n");

	pthread_create(&nonst1, NULL, nonsync, (void *)&nonspac1);
	pthread_create(&nonst2, NULL, nonsync, (void *)&nonspac2);
	pthread_create(&nonst3, NULL, nonsync, (void *)&nonspac3);

	//sleep(10);
	pthread_join(nonst1, (void **)NULL);
	printf("Unsync: n1:%d, res1:%d\n",nonspac1.n,nonspac1.res);
	
	pthread_join(nonst2, (void **)NULL);
	printf("Unsync: n2:%d, res2:%d\n",nonspac2.n,nonspac2.res);

	pthread_join(nonst3, (void **)NULL);
	printf("Unsync: n3:%d, res3:%d\n",nonspac3.n,nonspac3.res);

	

	//Demonstrating sync
	printf("\nDemonstrating SYNC THREAD\n");
	if(pthread_mutex_init(&mutex,NULL))
	{
		printf("\n Mutex init failed : %s \n",strerror(errno));
		exit(1);
	}
	
	pthread_create(&synct1, NULL, syncc, (void *)&synpac1);
	pthread_create(&synct2, NULL, syncc, (void *)&synpac2);
	pthread_create(&synct3, NULL, syncc, (void *)&synpac3);

	//sleep(10);
	pthread_join(synct1, (void **)NULL);
	printf("Safe: n1:%d, res1:%d\n",synpac1.n,synpac1.res);

	pthread_join(synct2, (void **)NULL);
	printf("Safe: n2:%d, res2:%d\n",synpac2.n,synpac2.res);

	pthread_join(synct3, (void **)NULL);
	printf("Safe: n3:%d, res3:%d\n",synpac3.n,synpac3.res);
	
	pthread_mutex_destroy(&mutex);

	return 0;
}
void inc(int n)
{
	int i;
	for (i=1;i<=n;i++)
	{
		glinc++;
	}
	return;
}
void* nonsync(void *ppac)
{
	int i;
	for(i=1;i<=((struct package*)ppac)->n;i++)
	{
		glnonsync++;
		//printf("i: %d\t",i);
		//printf("tid: %u\n",pthread_self());
	}
	((struct package*)ppac)->res = glnonsync;
	return ((void *)NULL);
}

void* syncc(void *ppac)
{
	
	int i;
	
	pthread_mutex_lock(&mutex);
	for(i=1;i<=((struct package*)ppac)->n;i++)
	{

		glsync++;
		
		//printf("i: %d\t",i);
		//printf("tid: %u\n",pthread_self());
	}
	((struct package*)ppac)->res = glsync;
	pthread_mutex_unlock(&mutex);
	return ((void *)0);
}

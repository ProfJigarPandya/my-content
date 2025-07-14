//Demonstrating thread-safe
// Topic: 12.5 Reentrancy w.r.t Thread Control
//  Threads are similar to signal handlers when it comes to reentrancy.
//  With both singal handlers and threads, multiple control can potentially call the same function at the same time.
//  If a function can be safely called by multiple threads at the same time, we say that the function is thread-safe. (safely means getting non-corrupted results.)
//  Many functions are not thread-safe because they return data stored in a static memory buffer. 
//  They are made thread-safe by changing their interface to require that the caller provide its own buffer.
//  Courtesy: Book - Advanced Programming in the UNIX Environment by W. Richard Stevens and Stephen A. Rago. 2nd Edition. Pearson.
//  Chapter 12. Thread Control.
//
//  Testing this program multiple times, few time it may incure unexpected results in thread unsafe calls. Because of the randomized thread swithing and the static/common memory for storing the results by the unsafe function.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct package
{
	int n;
	int res;
};

int addup(int n);
void* unsafe(void *ptrn);
void* safe(void *pac);

int main()
{
	pthread_t unst1,unst2,unst3;
	int n1=1000;void *pres1=NULL;
	int n2=2000;void *pres2=NULL;
	int n3=3000;void *pres3=NULL;
	
	pthread_t saft1,saft2,saft3;
	struct package pac1,pac2,pac3;
	pac1.n = n1;pac1.res=0;
	pac2.n = n2;pac2.res=0;
	pac3.n = n3;pac3.res=0;

	
	//Expected Result
	printf("\nExpected Result by regular functions\n");
	printf("Expected: n1:%d, res1:%d\n",n1,addup(n1));
	printf("Expected: n2:%d, res2:%d\n",n2,addup(n2));
	printf("Expected: n3:%d, res3:%d\n",n3,addup(n3));
	
	//Demonstrating unsafe
	printf("\nDemonstrating UNSAEF THREAD\n");

	pthread_create(&unst1, NULL, unsafe, (void *)&n1);
	pthread_create(&unst2, NULL, unsafe, (void *)&n2);
	pthread_create(&unst3, NULL, unsafe, (void *)&n3);

	//sleep(10);
	pthread_join(unst1, (void **)&pres1);
	printf("Unsafe: n1:%d, res1:%d\n",n1,*((int *)pres1));

	pthread_join(unst2, (void **)&pres2);
	printf("Unsafe: n2:%d, res2:%d\n",n2,*((int *)pres2));

	pthread_join(unst3, (void **)&pres3);
	printf("Unsafe: n3:%d, res3:%d\n",n3,*((int *)pres3));

	

	//Demonstrating safe
	printf("\nDemonstrating SAEF THREAD\n");

	pthread_create(&saft1, NULL, safe, (void *)&pac1);
	pthread_create(&saft2, NULL, safe, (void *)&pac2);
	pthread_create(&saft3, NULL, safe, (void *)&pac3);

	//sleep(10);
	pthread_join(saft1, (void **)NULL);
	printf("Safe: n1:%d, res1:%d\n",pac1.n,pac1.res);

	pthread_join(saft2, (void **)NULL);
	printf("Safe: n2:%d, res2:%d\n",pac2.n,pac2.res);

	pthread_join(saft2, (void **)NULL);
	printf("Safe: n3:%d, res3:%d\n",pac3.n,pac3.res);


}
int addup(int n)
{
	int sum=0,i;
	for (i=1;i<=n;i++)
	{
		sum+=i;
	}
	return sum;
}
void* unsafe(void *ptrn)
{
	int i;
	int localr=0;
	static int staticr;
	for(i=1;i<=*(int *)ptrn;i++)
	{
		localr = localr +i;
		//printf("i: %d\t",i);
		//printf("tid: %u\n",pthread_self());
	}
	staticr = localr;
	return ((void *)&staticr);
}
void* safe(void *ppac)
{
	
	int i;
	int localr=0;
	for(i=1;i<=((struct package*)ppac)->n;i++)
	{
		localr = localr +i;
		//printf("i: %d\t",i);
		//printf("tid: %u\n",pthread_self());
	}
	((struct package*)ppac)->res = localr;
	return ((void *)0);
}

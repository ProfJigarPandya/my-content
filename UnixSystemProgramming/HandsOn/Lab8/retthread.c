// Box #5:  Return value from a child

#include <pthread.h>
#include <stdio.h>

///////////////////////////////////////////////////////
void *ChildThread(void *Number)
{
	int N=(int)Number;
 	int i;  int total;

	total=0;

	for(i=1;i<=N;++i)
		{  total+=i; }

	pthread_exit((void *)total); // Notice the cast
	return 0;
}

///////////////////////////////////////////////////////
void *ChildThread2(void *pNumber)
{
	int N=*(int *)pNumber;
	printf("\n The number is %d",N);
 	int i;  int total;

	total=0;

	for(i=1;i<=N;++i)
		{  total+=i; }

	pthread_exit((void *)total); // Notice the cast
	return 0;
}


/////////////////////////////////////////////////////
int main(void)
{  
	pthread_t hThread;  int total;
	int n;
	printf("\n Enter n to sum from 1 to n ");
	scanf("%d",&n);
	//pthread_create(&hThread,NULL,ChildThread,(void *)n);
	pthread_create(&hThread,NULL,ChildThread2,(void *)&n);
	pthread_join(hThread,(void **)&total);

	printf("Total Sum=%d\n",total); return 0;
}

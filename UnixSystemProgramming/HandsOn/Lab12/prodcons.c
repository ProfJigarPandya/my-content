//producer consumer problem bounded buffer. 1 producer, 1 consumer
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


#define CAPACITY 5



int buffer[CAPACITY];
sem_t mutex;
sem_t full;
sem_t empty;

int producer()
{
	int plocation=0;
	int item=0;
	int temp;
	while(1)
	{
		item+=10;

		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[plocation]=item;	
		temp=plocation;
		plocation=(plocation+1)%CAPACITY;
		sem_post(&mutex);
		sem_post(&full);
		
		printf("\n produced %d at %d location",item,temp);
		//sleep
		sleep(1);//second
	}
}

int consumer()
{
	int clocation=0;
	int item=0;
	int temp;

	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		item=buffer[clocation];
		temp=clocation;
		clocation=(clocation+1)%CAPACITY;
		sem_post(&mutex);
		sem_post(&empty);
	
		printf("\n consumed %d from %d location",item,temp);
		//sleep
		sleep(1);//second
	}
}

int main()
{
	printf("\n Producre consumer start ");

	sem_init(&full, 0,0); //0 means not full
	sem_init(&empty, 0, CAPACITY); //available empty position
	sem_init(&mutex, 0, 1);//locked 


	pthread_t p,c;
	pthread_create(&p,NULL,(void *) producer,NULL);
	pthread_create(&c,NULL,(void *) consumer,NULL);
	
	pthread_join(p,NULL);
	pthread_join(c,NULL);

	printf("\n Producer consumer end ");
	
}

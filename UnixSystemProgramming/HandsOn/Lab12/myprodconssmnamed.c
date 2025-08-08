//producer consumer bounded buffer using shared memory and named semaphores
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define CAPACITY 5

sem_t *pmutex;
sem_t *pempty;
sem_t *pfull;

int main()
{
	const char full[]="sfull",empty[]="sempty",mutex[]="savail";

	
	int* shared_memory;
	int i;
	printf("\n producer consumer bounded buffer using shared memory  -  START");

	pfull=sem_open(full,O_CREAT,O_RDWR,0);
	pempty=sem_open(empty,O_CREAT,O_RDWR,CAPACITY);
	pmutex=sem_open(mutex,O_CREAT,O_RDWR,1);
	
	if( (pfull == SEM_FAILED) || ( pempty == SEM_FAILED ) || ( pmutex == SEM_FAILED) )
	{
		printf("\n Error in creating named semaphores ... :  %s",strerror(errno));
		return(1);
	}

	int cid=fork();
	if(cid==-1)
	{
		printf("\n Fork failed ");
		return (EXIT_FAILURE);
	}
	
	if(cid==0) //child consumer
	{
		printf("\n This is child as a consumer ");
		int clocation=0;
		int item=0;
		int temp;

		struct shmid_ds shmbuffer;
                int segment_size;
                const int shared_segment_size = 0x6400;//getpagesize()*number of default pages

                int segment_id;


                segment_id = shmget (124, shared_segment_size ,IPC_CREAT|S_IRUSR|S_IWUSR); //0x0000007c under key header in the output of ipcs command 124decimal

                if(segment_id==-1)
                {
                        printf("\n Error in shmget : %s",strerror(errno));
                        return(EXIT_FAILURE);
                }

                printf("\n Segment ID %d ",segment_id);

                shared_memory = (int*) shmat (segment_id, 0, 0);
                if( *((int *)shared_memory)==-1)
                {
                        printf("\n Error in shmat while trying to attach the shared memory segment. ");
                        return (EXIT_FAILURE);
                }

                printf ("shared memory attached at address %p\n", shared_memory);

                shmctl (segment_id, IPC_STAT, &shmbuffer);
                segment_size = shmbuffer.shm_segsz;
                printf ("segment size: %d\n", segment_size);


		while(1)
		{
			sem_wait(pfull);
			sem_wait(pmutex);
                        item=*(shared_memory+clocation);

			temp=clocation;
			clocation=(clocation+1)%CAPACITY;
			sem_post(pmutex);
			sem_post(pempty);
	
			printf("\n consumed %d from %d location",item,temp);
			sleep(1);//second
		}
		
	}
	else //parent producer
	{
		printf("\n This is parent as a producer ");
		int plocation=0;
		int item=0;
		int temp;
		
                struct shmid_ds shmbuffer;
                int segment_size;
                const int shared_segment_size = 0x6400;//getpagesize()*number of default pages

                int segment_id;


                segment_id = shmget (124, shared_segment_size ,IPC_CREAT|S_IRUSR|S_IWUSR); //0x0000007c under key header in the output of ipcs command 124decimal

                if(segment_id==-1)
                {
                	printf("\n Error in shmget : %s",strerror(errno));
                        return(EXIT_FAILURE);
                }

                printf("\n Segment ID %d ",segment_id);

                shared_memory = (int*) shmat (segment_id, 0, 0); 
                if( *((int *)shared_memory)==-1)
                {
                	printf("\n Error in shmat while trying to attach the shared memory segment. ");
                        return (EXIT_FAILURE);
                }

                printf ("shared memory attached at address %p\n", shared_memory);

                shmctl (segment_id, IPC_STAT, &shmbuffer);
                segment_size = shmbuffer.shm_segsz;
                printf ("segment size: %d\n", segment_size);

	
		while(1)
		{
			item+=10;
	
			sem_wait(pempty);
			sem_wait(pmutex);


			*(shared_memory+plocation) = item;

			temp=plocation;
			plocation=(plocation+1)%CAPACITY;
			sem_post(pmutex);
			sem_post(pfull);
			
			printf("\n produced %d at %d location",item,temp);
			//sleep
			sleep(1);//second
		}
	}


	printf("\n Press any key to continue" );
	getchar();
	
	sem_close(pfull);
	sem_close(pempty);
	sem_close(pmutex);

	sem_unlink(full);
	sem_unlink(empty);
	sem_unlink(mutex);

	
	printf("\n producer consumer bounded buffer using shared memory  -  END");
	getchar();
	
}


//shared memory demo; This program reads. 
#include <stdio.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


int main()
{

	char* shared_memory;
	struct shmid_ds shmbuffer;
	int segment_size;
	const int shared_segment_size = 0x6400;//getpagesize()*number of default pages

	int segment_id;	
	

        segment_id = shmget (124, shared_segment_size ,S_IRUSR);	//Based on common key value (e.g.124 here), two independent processes refer to same memory segment. Or process can ask segment_id using scanf.

	//printf("\n Enter segment id to read from ");
	//scanf("%d",&segment_id);

        if(segment_id==-1)
        {   
                printf("\n Error in shmget ");
                return(EXIT_FAILURE);
            
        }   

        printf("\n Segment ID %d ",segment_id);

	
	/* Reattach the shared memory segment, at a different address. */
	shared_memory = (char*) shmat (segment_id, (void*) 0x5000000, 0);
	printf ("shared memory reattached at address %p\n", shared_memory);

	/* Print out the string from shared memory. */
	printf ("READING FROM SHARED: %s\n", shared_memory);
	
	printf("\n Press any key to continue ");
	getchar();

	/* Detach the shared memory segment. */
	shmdt (shared_memory);

	/* Deallocate the shared memory segment. */
	shmctl (segment_id, IPC_RMID, 0);


	
}


//shared memory demo; Same program writes and reads from the memory. 
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
	


	segment_id = shmget (IPC_PRIVATE, shared_segment_size ,IPC_CREAT|S_IRUSR|S_IWUSR|IPC_EXCL);
	if(segment_id==-1)
	{
		printf("\n Error in shmget ");
		return(EXIT_FAILURE);
	
	}

	printf("\n Segment ID %d ",segment_id);

	/* Attach the shared memory segment. */
	shared_memory = (char*) shmat (segment_id, 0, 0);
	if( *((int *)shared_memory)==-1)
	{
		printf("\n Error in shmat while trying to attach the shared memory segment. ");
		return (EXIT_FAILURE);
	}
	printf ("shared memory attached at address %p\n", shared_memory);

	/* Determine the segment’s size. */
	shmctl (segment_id, IPC_STAT, &shmbuffer);
	segment_size = shmbuffer.shm_segsz;
	printf ("segment size: %d\n", segment_size);


	/* Write a string to the shared memory segment. */
	sprintf (shared_memory, "Hello, world. Testing shared memory");
	
	sleep(50);

	/* Detach the shared memory segment. */
	shmdt (shared_memory);

	
	
	/* Reattach the shared memory segment, at a different address. */
	shared_memory = (char*) shmat (segment_id, (void*) 0x5000000, 0);
	printf ("shared memory reattached at address %p\n", shared_memory);

	/* Print out the string from shared memory. */
	printf ("READING FROM SHARED: %s\n", shared_memory);

	/* Detach the shared memory segment. */
	shmdt (shared_memory);

	/* Deallocate the shared memory segment. */
	shmctl (segment_id, IPC_RMID, 0);


	
}


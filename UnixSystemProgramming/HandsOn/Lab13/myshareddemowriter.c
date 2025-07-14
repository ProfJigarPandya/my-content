//shared memory demo; This program writes.
#include <stdio.h>
#include <errno.h>
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


	//segment_id = shmget (IPC_PRIVATE, shared_segment_size ,IPC_CREAT|S_IRUSR|S_IWUSR|IPC_EXCL);
	segment_id = shmget (124, shared_segment_size ,IPC_CREAT|S_IRUSR|S_IWUSR); //0x0000007c under key header in the output of ipcs command 124decimal

	if(segment_id==-1)
	{
		printf("\n Error in shmget : %s",strerror(errno));
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
	
	printf("\n Press any key to continue ");
	getchar();

	/* Detach the shared memory segment. */
	shmdt (shared_memory);

	
}

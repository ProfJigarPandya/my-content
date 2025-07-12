/*
 * Write C programs which will communicate with each other using shared memory.
 *
 * (Use of shmget, shmat, shmdt system calls)
 *
 * READER. (must run after finishing the "WRITER" program. As no synchronization locks, etc worked out.)
 *
 * *
 *  gcc -Wall sharmemdemoWriter.c -o sharmemdemoWriter.o
 *  gcc -Wall sharmemdemoReader.c -o sharmemdemoReader.o
 *   
 *  ./sharmemdemoWriter.o 1121
 *  ./sharmemdemoReader.o 1121
 *
 */

#include <stdio.h>
#include  <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>



int main(int argc, char *argv[])
{
	int shmkey;
	int shmsize = 1025;
	int shmid;

	void *shmaddr=NULL;	

	shmkey = atoi(argv[1]);

	shmid = shmget(shmkey,shmsize,SHM_RDONLY);	
	if(shmid ==-1)
	{
		printf("\n Error in shmget %s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	printf("\n Valid shared memory identifier %d\n",shmid);

       	printf("\n Press any key to move on to attach \n");
       	getchar();	
       	
	shmaddr = shmat(shmid,NULL,0);

	if(shmaddr ==(void *)-1)
	{
		printf("\n Error in shmat %s\n ", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("\n Shmaddr %p\n",shmaddr);
	
	
	printf("Message From Peer: %s \n",(char *)shmaddr);
	

	printf("\n Press any key to move on to detach \n");
	getchar();

	shmdt(shmaddr);

	
	return(0);	
}

/*
 * Write C programs which will communicate with each other using shared memory.
 *
 * (Use of shmget, shmat, shmdt system calls)
 *
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

	if(argc != 2)
	{
		printf("\n Usage: %s keynumber ",argv[0]);
		exit(EXIT_FAILURE);
	}

	shmkey = atoi(argv[1]);
	shmid = shmget(shmkey,shmsize,IPC_CREAT|S_IRUSR|S_IWUSR|S_IRGRP);	
	if(shmid ==-1)
	{
		printf("\n Error in shmget %s \n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	printf("\n Valid shared memory identifier %d\n",shmid);
	
       shmaddr = shmat(shmid,NULL,0);

	if(shmaddr ==(void *)-1)
	{
		printf("\n Error in shmat %s\n ", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("\n Shmaddr %p\n",shmaddr);
	
	
	printf("\n Enter a message to pass on (max 1024 bytes)\n");
	//sprintf((char *)shmaddr,"%s","This is a personal message");
	scanf("%[^\n]",(char *)shmaddr);

	if(shmdt(shmaddr)==-1)
	{
		printf("\n Detach failed %s \n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("\n Detached successfully \n");
	}
	
	printf("\n Have a nice day ! ");
			
	return(0);	
}

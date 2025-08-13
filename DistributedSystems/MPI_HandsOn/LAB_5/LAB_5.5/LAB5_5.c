//Write MPI program to divide tasks into three groups based upon rank. Create new communication and then perform Collective Communication. Also show group communication.
#include "mpi.h"
#include <stdio.h>
#define NPROCS 15
main(int argc, char *argv[])
{
	int rank, new_rank, sendbuf, recvbuf, numtasks,ranks1[5]={0,1,2,3,4}, ranks2[5]={5,6,7,8,9},ranks3[5]={10,11,12,13,14};

	MPI_Group orig_group, new_group;
	MPI_Comm new_comm;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	
	if (numtasks != NPROCS)
	 {
		printf("Must specify MP_PROCS= %d. Terminating.\n",NPROCS);
		MPI_Finalize();
		exit(0);
	 }
	
	sendbuf = rank;

	/* Extract the original group handle */
	MPI_Comm_group(MPI_COMM_WORLD, &orig_group);

	/* Divide tasks into two distinct groups based upon rank */
	if (rank < 5) 
	{
	MPI_Group_incl(orig_group, NPROCS/3, ranks1, &new_group);
	}
	else if(rank < 10)
	{
	MPI_Group_incl(orig_group, NPROCS/3, ranks2, &new_group);
	}
	else
	{
	MPI_Group_incl(orig_group, NPROCS/3, ranks3, &new_group);
	}	
	MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm);
	MPI_Allreduce(&sendbuf, &recvbuf, 1, MPI_INT, MPI_SUM, new_comm);
	MPI_Group_rank (new_group, &new_rank);
	
	printf("rank= %d newrank= %d recvbuf= %d\n",rank,new_rank,recvbuf);
	
	MPI_Finalize();
}


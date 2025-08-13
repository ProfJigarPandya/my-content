Aim: Write a program for sum 1 to 1000 using group communication.


#include "mpi.h"
#include <stdio.h>
#define NPROCS 10
#define SIZE 5
#define range 1000

main(int argc, char *argv[])
{
	int rank, new_rank, sendbuf, result1,result2, numtasks,ranks1[5]={0,1,2,3,4}, ranks2[5]={5,6,7,8,9};
	
	
	int i=0,tag=1,source=0,num=0,receiveNum;	
	long int final_sum=0,result=0,sum=0;
	
	MPI_Status stat;
	MPI_Datatype rowtype;

	MPI_Group orig_group, new_group;
	MPI_Comm new_comm;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

	if (numtasks != NPROCS)
	 {
		printf("Must specify MP_PROCS= %d. Terminating.\n",NPROCS);
		MPI_Finalize();
		return 0;
	}

	sendbuf = rank;

	/* Extract the original group handle */	
	MPI_Comm_group(MPI_COMM_WORLD, &orig_group);

	/* Divide tasks into two distinct groups based upon rank */
	if (rank < NPROCS/2)
	 {
		MPI_Group_incl(orig_group, NPROCS/2, ranks1, &new_group);
	}
	else
	 {
		MPI_Group_incl(orig_group, NPROCS/2, ranks2, &new_group);
	}
		
	/* Create new new communicator and then perform collective communications */
	MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm);
	//MPI_Allreduce(&sendbuf, &recvbuf, 1, MPI_INT, MPI_SUM, new_comm);//MPI_Allreduce (&sendbuf,&recvbuf,count,datatype,op,comm)
	
	MPI_Group_rank (new_group, &new_rank);
	if(rank < NPROCS/2)
	{
	
		if (new_rank == 0)
		 {
			for (i=0; i<numtasks/2; i++)
			{
				
				MPI_Send(&num, 1, MPI_INT, i, tag,new_comm);
				
				num=num+range/numtasks;
				
			}
		}
		MPI_Recv(&receiveNum, 1, MPI_INT, source, tag,new_comm, &stat);
	
		for(i=(receiveNum+1);i<=receiveNum+(range/numtasks);i++)
		{
			sum=sum+i;
			
		}
	
	
		MPI_Allreduce(&sum, &result1, 1, MPI_LONG, MPI_SUM, new_comm);//MPI_Allreduce (&sendbuf,&recvbuf,count,datatype,op,comm)
		
		if(rank==0)
		{
			
			printf("result of group1 %ld\n",result1);
		}
	}
		else
		{
			num=(range/2)+1;	
			if (new_rank == 0)
			 {
				for (i=0; i<numtasks/2; i++)
				{
					
					
					MPI_Send(&num, 1, MPI_INT, i, tag,new_comm);
				
					num=num+range/numtasks;
					
				
				}
			}
			
			MPI_Recv(&receiveNum, 1, MPI_INT, source, tag, new_comm, &stat);
			
			for(i=(receiveNum);i<receiveNum+(range/numtasks);i++)
			{
				
				sum=sum+i;
			
			}
			
			MPI_Allreduce(&sum, &result2, 1, MPI_LONG, MPI_SUM, new_comm);//MPI_Allreduce (&sendbuf,&recvbuf,count,datatype,op,comm)
			
			if(rank==5)
			{
				MPI_Send(&result2, 1, MPI_LONG, 0, tag,MPI_COMM_WORLD);//send data to all combine communication world in which rank=0
				printf("result of group2 %ld\n",result2);
			}
		
		}
		if(rank==0)
		{
			MPI_Recv(&result, 1, MPI_LONG,5,tag,MPI_COMM_WORLD, &stat);//source=5 bcz in group 2 rank 5 process send data.
		
			final_sum=result1+result; //initinally store data in group 1 ,rank 0 store group 1 sum in recvbuf so no need to send data from group 1.
		
			printf("final_sum=%ld\n",final_sum);		

		}
	MPI_Finalize();
}


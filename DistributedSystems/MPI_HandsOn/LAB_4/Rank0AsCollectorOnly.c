//Aim:write a program for parellel summation of 1 to 20000


#include "mpi.h"
#include <stdio.h>
#define SIZE 5

main(int argc, char *argv[]) 
{
	int numtasks, rank, source=0, dest, tag=1, i;
	int a[SIZE][2] =				{{0,0},{1, 5000},
								{5001,10000},
								{10001,15000},
								{15001,20000}};
	int b[SIZE],c[SIZE],count=0,arr[SIZE];
	long int sum=0,sum1=0,result=0;
	
	MPI_Status stat;
	MPI_Datatype rowtype,rowtype1;

	MPI_Init(&argc,&argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Type_contiguous(2, MPI_INT, &rowtype);
	MPI_Type_commit(&rowtype);
	printf("\nNumTasks %d",numtasks);
	if (numtasks == SIZE)
	 {
		if (rank == 0)
		 {
			printf("\n Rank#0: Distributing tasks");
			for (i=1; i<numtasks; i++)
				MPI_Send(&a[i][0], 1, rowtype, i, tag, MPI_COMM_WORLD);
		}
		else
		{
	
		printf("\n Rank#%d Receiving Tasks",rank);

		MPI_Recv(b, 2, MPI_INT, source, tag, MPI_COMM_WORLD, &stat);
	
		for(i=b[0];i<=b[1];i++)
		{
			sum=sum+i;
		}

		printf("\n Rank#%d Submitting Result %d",rank,sum);
		MPI_Send(&sum, 1, MPI_LONG , 0, tag, MPI_COMM_WORLD);
		}
			
		if(rank==0)	
		{
			for(i=1;i<numtasks;i++)
			{			
						printf("\n Rank#0 Receiving from %d",rank);
						MPI_Recv(&c[i],1, MPI_LONG, i, tag, MPI_COMM_WORLD, &stat);
						printf("sum %d",c[i]);
						result = result + c[i];
			}
			
		printf("Result %lld\n",result);
		}
		
	}
	else
	
		printf("Must specify %d processors. Terminating.\n",SIZE);
		MPI_Type_free(&rowtype);
		MPI_Finalize();
}

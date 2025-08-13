Aim: Write a program for matrix multiplication using different size.


#include "mpi.h"
#include <stdio.h>
#define SIZE 4

main(int argc, char *argv[])
{
	int numtasks, rank, source=0, dest, tag=1, i,k,j,c[SIZE][SIZE],sum=0,result[SIZE][SIZE],receiveNum[SIZE];
	int B[SIZE+2][SIZE+1] ={2, 3, 2,2,3,
						5, 2, 4, 3,4,
						4, 3, 2,6,5,
						2, 2,3, 4,2,
						4, 3, 2,6,5,
						2, 2,3, 4,2};
	int A[SIZE][SIZE+2]={5,2,3,4,4,5,
						4,3,2,3,2,3,
						4,2,4,3,4,5,
						2,3,7,2,2,3};


	MPI_Status stat;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
if (numtasks == SIZE)//give numtasks=4 in terminal
{
			
			for(j=0;j<SIZE+1;j++)
			{
				sum=0;
				for(k=0;k<SIZE+2;k++)
				{
					sum=sum+A[rank][k]*B[k][j];
				}
			c[rank][j]=sum;
			
			}			

			
			MPI_Send(&c[rank],5, MPI_INT,0, tag, MPI_COMM_WORLD);			
		
			if(rank==0)
			{
				for (i=0; i<SIZE; i++)
				{
					
					MPI_Recv(&result[i], 5, MPI_INT, i, tag, MPI_COMM_WORLD, &stat);
					
				}
				
				printf("matrix A\n");
				for(i=0;i<SIZE;i++)
				{
					for(j=0;j<SIZE+2;j++)
					{
						printf("%d\t",A[i][j]);
					}
					printf("\n");
					}
	
				printf("matrix B\n");
				for(i=0;i<SIZE+2;i++)
				{
					for(j=0;j<SIZE+1;j++)
					{
						printf("%d\t",B[i][j]);
					}
					printf("\n");
				}
				
				printf("result\n");
				
				for(i=0;i<SIZE;i++)
					printf("%d\t%d\t%d\t%d\t%d\n",result[i][0],result[i][1],result[i][2],result[i][3],result[i][4]);
	
	
			}
}
MPI_Finalize();
}


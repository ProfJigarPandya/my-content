Aim: Write a program for matrix determinant.

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define NRA 5
/* number of rows in matrix A */
#define NCA 5
/* number of columns in matrix A */
#define NCB 5
#define n 5
/* number of columns in matrix B */
#define MASTER 0
/* taskid of first task */
#define FROM_MASTER 1
/* setting a message type */
#define FROM_WORKER 2
/* setting a message type */
int main (int argc, char *argv[])
{
int numtasks,
/* number of tasks in partition */
taskid,
/* a task identifier */
numworkers,
/* number of worker tasks */
source,
/* task id of message source */
dest,
/* task id of message destination */
mtype,
/* message type */
rows,
/* rows of matrix A sent to each worker */
averow, extra, offset,
i, j, k,l=1,m=0, rc;
float ratio;
int determinant;
/* misc */
float a[5][5]={1,2,3,3,5,3,2,1,2,2,1,2,3,4,5,1,1,8,1,2,7,2,1,3,2};
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
if (numtasks < 2 )
{ MPI_Abort(MPI_COMM_WORLD, rc);
exit(1); }
numworkers = numtasks-1;
if (taskid == MASTER)
{
/* Send matrix data to the worker tasks */
averow = NRA/numworkers;
extra = NRA%numworkers;
offset = 0;
mtype = FROM_MASTER;
for (dest=1; dest<=numworkers; dest++)
{ rows = (dest <= extra) ? averow+1 : averow;
MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
MPI_Send(&a[offset][0], rows*NCA, MPI_DOUBLE, dest, mtype,MPI_COMM_WORLD);
offset = offset + rows;
} /* Receive results from worker tasks */
mtype = FROM_WORKER;
for (i=1; i<=numworkers; i++)
{ source = i;
MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
MPI_Recv(&determinant, 1, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD,
&status);
}
printf("determinant = %d\n",determinant);
}
if (taskid > MASTER)
{
mtype = FROM_MASTER;
MPI_Recv(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
MPI_Recv(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
MPI_Recv(&a, rows*NCA, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD,
&status);
for(i=0;i<rows;i++)
{
determinant = determinant + (a[0][i]*(a[1][(i+1)%rows]*a[2][(i+2)%rows] -
a[1][(i+2)%rows]*a[2][(i+1)%rows]));
}
mtype = FROM_WORKER;
MPI_Send(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
MPI_Send(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
MPI_Send(&determinant,1, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD);
}
MPI_Finalize();
}

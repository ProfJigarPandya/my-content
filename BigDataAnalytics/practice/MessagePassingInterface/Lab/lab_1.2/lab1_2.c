//Aim: Write MPI program to demonstrate the use of Mpi_send and Mpi_recv function and print the processes recieves data using blocking message passing routine.


#include "mpi.h"
#include <stdio.h>
main (int argc, char *argv[])
{
  int numtasks, rank, dest, source, rc, count, tag = 1;
  char inmsg, outmsg = 'x';
  MPI_Status Stat;
  MPI_Init (&argc, &argv);
  MPI_Comm_size (MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  if (rank == 0)
    {
      dest = 1;
      source = 1;
      outmsg = 'y';
      rc = MPI_Send (&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
      rc = MPI_Recv (&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
      printf ("recveid message from process 1 is %c \n", inmsg);
    }
  else if (rank == 1)
    {
      dest = 0;
      source = 0;
      outmsg = 'z';
      rc = MPI_Recv (&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
      rc = MPI_Send (&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
      printf ("recveid message from process 0 is %c \n", inmsg);
    }
  rc = MPI_Get_count (&Stat, MPI_CHAR, &count);
  printf
    ("Task %d: Received %d char(s) from task %d with tag %d dest = %d source = %d \n",
     rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, dest, source);
  MPI_Finalize ();
}

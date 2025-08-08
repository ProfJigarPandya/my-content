//Aim: Write MPI program to show how many tasks are running and what is the rank of it.

//Program:
//#include "/usr/include/mpich-x86_64/mpi.h"
#include "mpi.h"
//#include "/usr/include/mpich-3.2-x86_64/mpi.h"
//#include "/usr/include/mpich-x86_64/mpi.h"
//#include "/usr/src/kernels/3.10.0-327.el7.x86_64/include/linux/mpi.h"
//#include "/usr/src/kernels/3.10.0-514.6.2.el7.x86_64/include/linux/mpi.h"

#include <stdio.h>
int
main (int argc, char *argv[])
{
  int numtasks, rank, len, rc;
  char hostname[MPI_MAX_PROCESSOR_NAME];
  rc = MPI_Init (&argc, &argv);
  if (rc != MPI_SUCCESS)
    {
      printf ("Error starting MPI program. Terminating.\n");
      MPI_Abort (MPI_COMM_WORLD, rc);
    }
  MPI_Comm_size (MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name (hostname, &len);
  printf ("#Number of tasks= %d My rank= %d Running on %s\n", numtasks, rank,
	  hostname);
/******* do some work *******/
  MPI_Finalize ();
  return (0);
}

/*
 * Write a program which performs matrix multiplication through
 * multithreading. Write a ‘C’ program on Linux platform which performs
 * matrix multiplication for matrices of dimensions R1 X N and N X C2. Every
 * element of the resusingloopant matrix of size R1 X C2 must be calculated
 * through different thread.
 * 
 * //This program can be updated to have local arrays and pass source arrays to
 * thread and let it return resulting element which you then store in result
 * array.
 * 
 */
#include <stdio.h>
#include <pthread.h>
#define R1 1
#define N 3
#define C2 4

struct matele {
	int		i         , j;
};

//Example1:
int		m1         [R1][N] = {{3, 4, 2}}, //R1xN
		m2            [N][C2] = {{13, 9, 7, 15}, {8, 7, 4, 6}, {6, 4, 0, 3}}, //NxC2
		resusingthread[R1][C2] = {{0}};


void* tmult(void *arg)
{
	int		k;
	struct matele  *pm = (struct matele *)arg;
	for (k = 0; k < N; k++) {
		resusingthread[pm->i][pm->j] += (m1[pm->i][k] * m2[k][pm->j]);
	}
	return 0;
}
int 
main()
{

	int		i         , j;
	pthread_t	t     [R1][C2];
	struct matele	me[R1][C2];

	printf("\n Matrix multiplication using threads.");


	//Call threads
		for (i = 0; i < R1; i++) {
		for (j = 0; j < C2; j++) {
			me[i][j].i = i;
			me[i][j].j = j;

			pthread_create(&t[i][j], NULL, tmult, (void *)&me[i][j]);
		}
	}

	//wait for processing
		for (i = 0; i < R1; i++) {
			for (j = 0; j < C2; j++) {
				pthread_join(t[i][j], (void **)NULL);
			}
		}

	printf("\n Result using Threads \n");
	for (i = 0; i < R1; i++) {
		for (j = 0; j < C2; j++) {
			printf("\t %d", resusingthread[i][j]);
		}
		printf("\n");
	}
	return (0);
}

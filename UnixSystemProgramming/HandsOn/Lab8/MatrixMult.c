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
#define R1 1
#define N 3
#define C2 4

int		m1         [R1][N] = {{3, 4, 2}}, //R1xN
		m2            [N][C2] = {{13, 9, 7, 15}, {8, 7, 4, 6}, {6, 4, 0, 3}}, //NxC2


resusingloop[R1][C2] = {{0}}; //R1xC2


void lmult(int i,int j) 
{ 
	int k ; for(k=0;k<N;k++) 
	{
 	 	resusingloop[i][j]+=(m1[i][k]*m2[k][j]); 
	}
	return ; 
}
 

int 
main()
{

	int		i         , j;

	printf("\n Matrix multiplication using loops");

	
	for(i=0;i< R1; i++) 
	{ 
		for(j=0;j<C2;j++) 
		{ 
			lmult(i,j); 
		} 
	}
	  
	printf("\n Result using loops \n"); 
	for(i=0;i<R1;i++) 
	{
	  	for(j=0;j<C2;j++) 
		{ 
			printf("\t%d",resusingloop[i][j]); 
		}
	  	printf("\n"); 
	}
	 


	return (0);
}

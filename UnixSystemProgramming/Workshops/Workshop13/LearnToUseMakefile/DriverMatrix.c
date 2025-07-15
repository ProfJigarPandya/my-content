/* 
Driver program for using my matrix library 
DriverMatrix.c
*/

#include <stdio.h>
#include "Matrix.h"
#define R 3
#define C 3
int main()
{
	int	m1[R][C]={{1,2,3},{4,5,6},{7,8,9}},
		m2[R][C]={{11,12,13},{14,15,16},{17,18,19}},
		m[R][C],
		status
	;
	/*
	int i,j;
	printf("Please, enter two %dx%d matrices ",R,C);
	for(i=0;i<R;i++)
	{
	 	for(j=0;j<C;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	for(i=0;i<R;i++)
	{
	 	for(j=0;j<C;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}*/
	
	
	status=addmatrices(m1,m2,m);

	if(status==0)
	{
		printf("\n Addition of two matrices\n");
		displaymatrix(m);
	}	
	else
		printf("Two matrices of different size can not be added.");

	return 0;
}

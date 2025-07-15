#include <stdio.h>
#define R 3
#define C 3
void 
displaymatrix(int m[][C])
{
	int		i         , j;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
}

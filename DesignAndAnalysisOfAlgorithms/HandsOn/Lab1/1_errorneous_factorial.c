//gcc -g efact.c -o efact.o
//gdb efact.o
//break <ln>
//info breakpoints
//run
//n
//s
//c
//output <variablename>

#include <stdio.h>
int main()
{
	int i, num, j;
	printf ("Enter the number: ");
	scanf ("%d", &num );
	for (i=1; i<num; i++)
		j=j*i;
	printf("The factorial of %d is %d\n",num,j);
}

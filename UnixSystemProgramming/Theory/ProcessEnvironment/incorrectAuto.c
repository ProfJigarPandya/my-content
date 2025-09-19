#include <stdio.h>
int* udf()
{
	int *pResultUDF=NULL;
	int resultUDF=15;
	pResultUDF=&resultUDF;
	return pResultUDF;
}
int main()
{
	int *pResultMain=NULL;
	pResultMain=udf();
	printf("%d",*pResultMain);
	return(0);
}

#include <stdio.h>
#define MAX 100
int main()
{
	int i;
	for(i=1;i<=MAX;i++)
		printf("%d\n",rand(100)%MAX);
}

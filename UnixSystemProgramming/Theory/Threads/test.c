#include <stdio.h>
int addup(int n);
int main()
{
	int i;
	int res=0;
	printf("%d\n",addup(1000));
	printf("%d\n",addup(2000));
	
	
}

int addup(int n)
{
	int sum=0,i;
	for (i=1;i<=n;i++)
	{
		sum+=i;
	}
	return sum;
}

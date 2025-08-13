#include <stdio.h>
int main()
{
	char data[256];
	printf("\n testing chdir ");
	if(!chdir("/home/user1/ch4_dir/d1/d2"))
	{
		printf("\n Changed ");		
		getcwd(data,256);
		printf("%s",data);	
	
	}
	else
	{
		printf("\n Could not change");
	}
}

#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("uid is %d and gid is %d",getuid(),getgid());
	return 0;
}


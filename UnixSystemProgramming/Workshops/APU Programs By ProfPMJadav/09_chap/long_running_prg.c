#include "../pmj.h"

int main(void)
{
	int count=100;

	while(1) {
		sleep(1);
		printf("%d\n", count--);
	}
}


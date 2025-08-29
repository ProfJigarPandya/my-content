#include <stdio.h>
//Explanation of L-Value and R-Value concept in C
//Linux Shell use $ symbol to read the environment/shell variables.

int main()
{
	//Left side of assignment operator known as L-Value, we are interested in writing to memory; 

	//Right side of assignment operator known as R-Value, we are interested in reading from memory

	//C designer founded smartness based on the position w.r.to assignment operator,for the same name "x", when to read and when to write is decided automatically. 

	//Unlike Linux shell where for variable reading user has to especially use $ symbol. i.e. export PATH=$PATH:"my custom directory location for commands". Compare to C like syntax PATH=PATH+"" 

	//Array name is a constant pointer having no user space(developer) memory for the name itself and hence can not be modified/written to. 

	//Similarly expressin a+b has memory from kernel space but not avalilable to user/developer.
	
	//error: assignment of read-only variable ‘i’
	const int i=0;
	i=i+1;
	printf("\n %d ",i);

	//error: lvalue required as increment operand
	int arr[10];
	arr++;

	//error: lvalue required as left operand of assignment
	int a=1,b=2;
	a+b=10;
}


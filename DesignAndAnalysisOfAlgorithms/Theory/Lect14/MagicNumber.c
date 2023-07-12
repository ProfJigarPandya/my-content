
#include <stdio.h>
#include <stdlib.h>

//This program finds and prints Digit Cells number of length 10.
//Digit Cells is defined as , value at each cell/position (0 to 9 from left to right), indicates total number of occurances of that digit in the whole number.
//In the 10 cells shown here, you are to inscribe a 10-digit number such that the digit in the first cell tells how many zeros are in the entire 10-digit number, the digit in the cell marked "1" tells how many 1's are in the number, and so on. Thus, if the "4" cell has a 2 in it, then there are two 4's somewhere in the 10-digit number.
//http://ohiorc.org/for/math/stella/setintro/problem.aspx?id=106#


int isMagic(int arr[])
{
	int count[10],ci=0,i=0,j=0;
	
	for(i=0;i<10;i++)
	{
		ci=0;
		for(j=0;j<10;j++)
		{
			if(arr[j]==i)
				ci++;
		}
		count[i]=ci;
	}
	
	for(i=0;i<10;i++)
	{
		if(count[i]!=arr[i])
			return 0;
	}
	
	if(i==10)
		return 1;
	else
		return 0;
}

void updateMagic(int arr[])
{
	int ci,i,j;
	
	for(i=0;i<10;i++)
	{
		ci=0;
		for(j=0;j<10;j++)
		{
			if(arr[j]==i)
				ci++;
		}
		arr[i]=ci;
	}
}


int main()
{
 int arr[]={9,0,0,0,0,0,0,0,0,0};
 //int arr[]={6,2,1,0,0,0,1,0,0,0};
 
 
 system("clear");
 printf("Hello World. ");
 
 
 while(1)
 {
	 
   if(isMagic(arr)==1)
   {
	  printf("\n Below is a magic number");
	  printf("\n %d %d %d %d %d %d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);	  
	  break;
   }
   else
   {

	   updateMagic(arr);
	   printf("\n %d %d %d %d %d %d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);
	   
   }
 }	
 
 printf("Have a nice day! ");
 return 0; 
}

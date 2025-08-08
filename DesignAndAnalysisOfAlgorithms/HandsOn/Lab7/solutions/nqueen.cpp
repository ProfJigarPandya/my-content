#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>

int array[6]={0};
int ispromising(int row,int pos)
{
 for(int j=1;j<row;j++)
 {
  if( (array[j] == pos) || ( abs(j-row) ==  abs(array[j]-pos) ) ) //diagonally threatening
  {
	return 0;
  }
 }
 return 1;
}

void nqueen(int row,int n)
{
  int pos;
  for(pos=1;pos<=n;pos++)
  {
   if(ispromising(row,pos))
   {
	array[row] = pos;
	if(row==n)
	{
		cout<<"\n Solution ";
		for(int l=1;l<=n;l++)
		{
		   cout<<"\n"<<array[l];
		}
	}
	else
		nqueen(row+1,n);
   }
  }
}

void main()
{
 clrscr();

 nqueen(1,5);

 getch();
}
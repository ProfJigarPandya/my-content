#include <stdio.h>
#include <iostream.h>
#include <conio.h>

void main()
{

 clrscr();
 int nad=1000,nper=60;
 for(int i=1;i<=4;i++)
 {
  for(int j=1;j<=4;j++)
  {
	for(int k=1;k<=4;k++)
	{
		printf("\ninsert into jf_adm values (%d,%d,%d,%d,%d);",i,j,k,nad,nper);
		nad+=100;
		nper = nper + 10;
		if(nper==100){ nper = 60;}

	}
  }
 }





 getch();
}
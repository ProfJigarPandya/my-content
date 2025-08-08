#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define MAXCA 3
#define MAXAMT 20
int mini(int x,int y)
{
 if(x<y) return x;
 else return y;
}
void main()
{
 int d[MAXCA]={1,4,6};
 int c[MAXCA][MAXAMT+1];
 int money;

 clrscr();
 for(int i=0;i<MAXCA;i++)
 {
   c[i][0] = 0;
 }

 for(i=0;i<MAXCA;i++)
 {
  for(int j=1;j<=MAXAMT;j++)
  {
     if(i==0 && j<d[i])
	c[i][j] = 999;
     else if(i==0)
     {
	c[i][j] = 1 + c[0][j-d[0]];
     }
     else if(j<d[i])
     {
	c[i][j] = c[i-1][j];
     }
     else
     {
	c[i][j] = mini(c[i-1][j],1+c[i][j-d[i]]);
     }
  }
 }

 cout<<"\n Enter amount from 1 to 20";
 cin>>money;

 cout<<"\n Minimum total coin needed are.... "<<c[2][money];

 getch();
}

/*
c[0]: { 0, 1, 2, 3, 4, 5, 6, 7, 8 }
c[1]: { 0, 1, 2, 3, 1, 2, 3, 4, 2 }
c[2]: { 0, 1, 2, 3, 1, 2, 1, 2, 2 }
*/

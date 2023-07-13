/* AIM: SOLVE THE KNAPSACK PROBLEM USING BACKTRACKING */
/*
   * 0/1 KNAPSACK ... SO, FRACTION OF OBJECT CANT BE SELECTED
   * INFINITE NUMBER OF OBJECTS FOR GIVEN WEIGHT ARE AVAILABLE..
*/

#include <stdio.h>
#include <conio.h>
#include <process.h>

#define MAX 10

//int vw[MAX][2]={{3,2},{5,3},{6,4},{10,5}};

int vw[MAX][2]={0};
int tsel[MAX]={0};
int fsel[MAX]={0};

int n;
int capacity;


int fun(int tweight,int c_obj,int c_value)
{
   static int max=0;
   for(int i=c_obj;i<n;i++)
   {
     if(tweight+vw[i][1] > capacity)
     {
	if(max<c_value)
	{
	  max = c_value;
	  for(int j=0;j<n;j++)
	     fsel[j] = tsel[j];
	}
	break;
      }
	tsel[i]++;
	fun(tweight+vw[i][1],i,c_value+vw[i][0]);
	tsel[i]--;
   }
  return max;
}
void sortw()
{
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-i-1;j++)
  {
	int t;
	if(vw[j][1] > vw[j+1][1])
	{
		t = vw[j][0];         // exchange value
		vw[j][0] = vw[j+1][0];
		vw[j+1][0] = t;

		t = vw[j][1];         // exchange weight
		vw[j][1] = vw[j+1][1];
		vw[j+1][1] = t;
	}
  }
 }
}
void main()
{

 clrscr();
 int mval,to=0;


 printf("\n Enter how many distinct object ");
 scanf("%d",&n);

 if(n>MAX)
 {
	printf("\n Array limit is of %d distinct objects only ",MAX);
	exit(0);
 }

 printf("\n Enter Weight and Value ");
 for(int k=0;k<n;k++)
 {
   printf("\n Enter weight of object %d  => ",k+1);
   scanf("%d",&vw[k][1]);
   printf("\n Enter Value of object %d  => ",k+1);
   scanf("%d",&vw[k][0]);
 }


 printf("\n Enter Knapsack capacity ");
 scanf("%d",&capacity);

 sortw();

 mval = fun(0,0,0);

 printf("\n Input ");
 printf("\nObjNo.  Weight\t\tValue  ");
 for(int j=0;j<n;j++)
   printf("\n %d\t%d\t\t%d",j+1,vw[j][1],vw[j][0]);

 printf("\n\n Knapsack capacity %d",capacity);




 printf("\n\n\nObjNo  Object Weighted        Count   iWeight    iValue   ");
 printf("\n\n\n******************************************************************");
 for(int i=0;i<n;i++)
 {
	printf("\n%d\t%d\t\t%d\t%d\t%d",i+1,vw[i][1],fsel[i],vw[i][1]*fsel[i],fsel[i]!=0?vw[i][0]:0);
	to+=fsel[i];
 }
 printf("\n******************************************************************");
 printf("\n\n\t\t    max possible profit %d", mval);
 printf("\n******************************************************************");


 printf("\n Total ojects selected %d",to);




 getch();
}
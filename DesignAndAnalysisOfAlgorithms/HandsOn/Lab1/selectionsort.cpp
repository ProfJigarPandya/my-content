/* selection sort */

#include <stdio.h>
#include <conio.h>
#include <iostream.h>

#define MAX 10
void main()
{
 int array[MAX];
 int n;
 int max,index;
 clrscr();
 cout<<"\n How many elements to be sorted ";
 cin>>n;
 if(n>MAX)
 {
	cout<<"\n Sorry, not enough space:";
	return;
 }
 for(int i=0;i<n;i++)
 {
  cin>>array[i];
 }

 for(i=n-1;i>=0;i--)
 {
   max = array[0];
   index = 0;
   for(int j=0;j<=i;j++)
   {
    if(array[j]>max)
    {
	max = array[j];
	index = j;
    }
   }
   int temp;
   temp =array[i];
   array[i] = array[index];
   array[index] = temp;
  }

  cout<<"\n Data sorted in ascending order ";
  for(i=0;i<n;i++)
    cout<<"\n"<<array[i];

 getch();
}
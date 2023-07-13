/* insertion sort using array*/

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

 //assume that array[0] is sorted and insert 1 to last element into sorted array
 // so that list remains sorted.....
 for(i=1;i<n;i++)
 {
   int temp;
   temp = array[i];

   for(int j=i-1;j>=0;j--)
   {
    if(temp<array[j])
    {
	array[j+1] = array[j];
    }
    else
      break;
   }

    array[j] = temp;

  }

  cout<<"\n Data sorted in ascending order ";
  for(i=0;i<n;i++)
    cout<<"\n"<<array[i];

 getch();
}
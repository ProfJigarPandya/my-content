/* insertion sort using array*/

#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 10

int main()
{
 int array[MAX];
 int n;
 int i,j;
 int temp;
 cout<<"\n How many elements to be sorted ";
 cin>>n;
 if(n>MAX)
 {
	cout<<"\n Sorry, not enough space:";
	return 0;
 }
 for(int i=0;i<n;i++)
 {
  cin>>array[i];
 }

 //assume that array[0] is sorted and insert 1 to last element into sorted array
 // so that list remains sorted.....
 i=1;
 while(i<n)
 {
   temp = array[i];

   j=i-1;
   while((j>=0)&&(temp<array[j]))
   {
	array[j+1] = array[j];
    	j--;
   }

   array[j+1] = temp;
   i++;

  }

  cout<<"\n Data sorted in ascending order ";
  for(i=0;i<n;i++)
    cout<<"\n"<<array[i];

 return 0;
}

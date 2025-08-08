#include <iostream.h>
#include <conio.h>
int bsearch(int low,int high,int blockofdata[],int tobesearched)
{
 int mid = (low + high ) /2;
 if(low>high)
	return -1;
 else if(blockofdata[mid] == tobesearched)
	return mid;
 else
 {
	if(tobesearched < blockofdata[mid])
	      return bsearch(low,mid-1,blockofdata,tobesearched);
	else
	      return bsearch(mid+1,high,blockofdata,tobesearched);
 }
}
void main()
{
clrscr();
int temp;
int data[10]={1,2,3,4,5,6,7,8,9,10};
if((temp=bsearch(0,9,data,4))==-1)
	cout<<"\n element is not in the list ";
else
	cout<<"\n element at index "<<temp+1;
getch();

}
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <process.h>

int partition(int arr[],int lb,int ub)
{
	int key = arr[lb];

	if(lb<ub)
	{
	    int flag=1;
		int i,j;
		i=lb+1;
		j=ub;

	    while(flag==1)
	    {
		while(arr[i]<key)
		{
		  i++;
		}
		while(arr[j]>key)
		{
			j--;
		}
		if(i<j)
		{
			int temp;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
			flag=0;
	    }

	    int t;
	    t = arr[lb];
	    arr[lb] = arr[j];
	    arr[j] = t;
	    return j;
	}
	else
	   return -1;
}

void quicksort(int arr[],int lb,int ub)
{
  int j;
  j=partition(arr,lb,ub);
  if(j!=-1)
  {
	quicksort(arr,lb,j-1);
	quicksort(arr,j+1,ub);
  }
}

void main()
{
	clrscr();
	int arr[]={44,75,12,221,40,45,10,36};
	quicksort(arr,0,7);
	for(int i=0;i<8;i++)
		cout<<endl<<arr[i];
	getch();
}

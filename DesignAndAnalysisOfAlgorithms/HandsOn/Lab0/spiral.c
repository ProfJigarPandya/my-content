//Spiral generation. Change the MAX defined value and run the program for your choice of positive number.
/*
 *      1     2     3     4     5
 *     16    17    18    19     6
 *     15    24    25    20     7
 *     14    23    22    21     8
 *     13    12    11    10     9
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX 15
#define BORDERS 4
#define CORNERS 4
#define SIZEOFFSET 2

enum DIRECTION {NONE,RIGHT,BOTTOM,LEFT,TOP};

void displaydata(int arr[][MAX]);
void spiral(int arr[][MAX]);
int main()
{
 int arr[MAX][MAX]={0};
 spiral(arr);
 displaydata(arr);
 return(0);
}
void displaydata(int arr[][MAX])
{
 int i,j;
 //printf("\n******SPIRAL******\n");
 for(i=0;i<MAX;i++)
 {
	for(j=0;j<MAX;j++)
	{
		printf("%6d",*(*(arr+i)+j));
	}
	printf("\n");
 }
}
void spiral(int arr[][MAX])
{ 
  enum DIRECTION direction=NONE;
  int *ptr=(int *)arr;
  int *base=(int *)arr;
  int csize=(MAX);//The current square box size
  int data=1;
  int outers=BORDERS*csize-CORNERS;//Elements of four borders but four corners are counted one time only
  int n;
  direction=RIGHT;//indicates the movement of direction

  //printf ("\n base %d, csize %d, outers %d\n",*base,csize,outers);
  //scanf("%d",&n);
  //while(data<=n)
  while(data<=MAX*MAX)
  {
	*ptr=data;
	switch(direction)
	{
		case RIGHT:	
				ptr++;
				//change the direction if needed
				if(ptr==(base+csize))
				{
					direction=BOTTOM;			
					ptr--;
					ptr=ptr+MAX;
				}
				break;
		case BOTTOM:
				ptr=ptr+MAX; //Jump number of columns to reach to next element in the same column
				//change the direction if needed
				if(ptr>(base+(csize*MAX)))
				{
					direction=LEFT;			
					//ptr=ptr-csize;
					ptr=ptr-MAX;
					ptr--;
				}
				break;
		case LEFT:
				ptr--;
				//change the direction if needed
				if(ptr<(base+(MAX*(csize-1))))
				{
					direction=TOP;			
					ptr++;
					ptr=ptr-MAX;
				}
				break;
		case TOP:
				ptr=ptr-MAX;  //Jump number of columns to reach to previous element in th same column	
				//change the direction if needed
				if(ptr==base)
				{
					direction=RIGHT;			
					ptr=ptr+MAX;
					ptr++;
				}
				break;
		default:
				exit(1);
	}
	
	//recalculate csize
	if(data==outers)
	{
		
		base=base+MAX+1;
		csize-=SIZEOFFSET;
		outers=outers+(BORDERS*csize-CORNERS);
		//printf ("\n base %d, csize %d, outers %d\n",*base,csize,outers);
	}
	
	//printf("\n%d",data);
	data++;
	
  }
  	
}

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAXW 12
#define MAXOBJ 10

void findprofit(int wv[][3],int v[][MAXW],int nobjs,int tw)
{

  int i,j,k;
  // if weights of all objects are greater than capacity
  for(i=0;i<nobjs;i++)
  {
     if(wv[i][0]<tw-1)
     {
	break;
     }
  }
  if(i==nobjs)
  {
	cout<<"\n All the weights are greater than capacity of knapsack";
	cout<<"\n Not a single object can be selected ";
	return;
  }
  for(i=0;i<nobjs;i++)
  {
    j=0;
    v[i][j]=0;
    j++;
    for(;j<tw;j++)
    {
	int wi = wv[i][0];
	if(i==0 )
	{
	     v[i][j] = wv[i][1];
	}
	else
	{
//	     logic for v[i][j] = max(v[i-1][j], (v[i-1][j-wi]) + (v[i][1]) );
	     int x,y;
	     x = v[i-1][j];
	     if(j-wi>=0)
	     {
	       y = v[i-1][j-wi] + wv[i][1];
	     }
	     else
	     {
		    y = v[i-1][j];
	     }
	     if(x>y)
	     {
		v[i][j] = x;
	     }
	     else
	     {
		v[i][j] = y;
	     }
	}

    }
  }
}
void findobjtoselect(int wv[][3],int v[][MAXW],int nobjs,int tw)
{
 int i,j=tw-1;
 for(i=nobjs-1;i>=0;i--)
 {
	if(v[i][j] == v[i-1][j])
	{
		continue;
	}
	wv[i][2] = 1; // selected
	j = j - wv[i][0];
	if(j==0)
	  return;

 }
}
void displayres(int wv[][3],int nobjs)
{

 int total=0;
 cout<<"\n RESULT \n ";
 cout<<" Weight  Value  SELECT (y/n) ";
 for(int i=0;i<nobjs;i++)
 {
  if(wv[i][2] == 1)
  {
	cout<<"\n"<<setw(10)<<wv[i][0]<<setw(10)<<wv[i][1]<<setw(7)<<"Yes";
	total+=wv[i][1];
  }
  else
	cout<<"\n"<<setw(10)<<wv[i][0]<<setw(10)<<wv[i][1]<<setw(7)<<"NO";
 }
 cout<<"\n Total profit "<<total;
}
void main()
{

 int  profit[MAXOBJ][MAXW]={0};
 int wv[MAXOBJ][3]; // weight value  status0notselected
 int nobjs,tw;

 clrscr();

 cout<<"\n Enter number of total distinct objects ";
 cin>>nobjs;
 cout<<"\n Enter Values ";
 for(int i=0;i<nobjs;i++)
 {
	cout<<"\n Enter weight and value for"<<i<<"object";
	cin>>wv[i][0]>>wv[i][1];
	wv[i][2] = 0; // not selected
 }
 cout<<"\n Enter capacity of knapsack ";
 cin>>tw;
 tw+=1; // for oth
 findprofit(wv,profit,nobjs,tw);
 findobjtoselect(wv,profit,nobjs,tw);
 displayres(wv,nobjs);

 getch();
}
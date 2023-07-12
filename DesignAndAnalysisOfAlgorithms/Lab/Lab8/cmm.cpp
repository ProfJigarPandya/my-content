/*
      pg. 308 Algo by Cormren
      long int dims[NMAX+1]={30,35,15,5,10,20,25};
      The minimum calculation required is 15125
	 (( M1 )( M2 M3))    (( M4 M5)( M6 ))

      exercise pg308 Algo by Cormen
      long int dims[NMAX+1]={5,10,3,12,5,50,6}; // change NMAX to 6 at top
       The minimum calculation required is 2010
       ( M1 M2)  (( M3 M4)( M5 M6))

      pg.272 Algo by Brately
      long int dims[NMAX+1]={13,5,89,3,34};
      The minimum calculation required is 2856
	 (( M1 )( M2 M3))  ( M4 )
*/


#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define NMAX 10

struct SOL
{
 short int minlli;
 short int minllj;
 short int minrri;
 short int minrrj;
};
struct SOL sol[NMAX][NMAX];
void dispresult(short int l1,short int u1,short int l2,short int u2)
{
  int flag1=0,flag2=0;
  static int cc=1;
  if(l1==u1)
  {
	printf("( M%d )",cc);
	cc++;
	flag1=1;
  }
  if(l1==u1-1)
  {
	int t1=cc++;
	int t2=cc++;
	printf("( M%d M%d)",t1,t2);
	flag1=1;
  }

  if(flag1==0)
  {
	  cout<<"  (";
	  dispresult(sol[l1][u1].minlli,sol[l1][u1].minllj,sol[l1][u1].minrri,sol[l1][u1].minrrj);
	  cout<<")  ";
  }

  if(l2==u2)// || l2==u2-1 )
  {
	printf("( M%d )",cc);
	cc++;
	flag2=1;
  }
  if(l2==u2-1 )
  {
	int t1=cc++;
	int t2=cc++;
	printf("( M%d M%d)",t1,t2);
	flag2=1;
  }

  if(flag2==0)
  {
  cout<<"  (";
  dispresult(sol[l2][u2].minlli,sol[l2][u2].minllj,sol[l2][u2].minrri,sol[l2][u2].minrrj);
  cout<<")  ";
  }
}

void main()
{
// long int dims[NMAX+1]={13,5,89,3,34};  //change NMAX to 4 at top
// long int dims[NMAX+1]={30,35,15,5,10,20,25}; // change NMAX to 6 at top
long int dims[NMAX+1]={5,10,3,12,5,50,6}; // change NMAX to 6 at top
// long int dims[NMAX+1];


 long int matrix[NMAX][NMAX];

 long int minval,tempval;
 short int minlli,minllj,minrri,minrrj;
 int nnn=6;
 clrscr();
/*
 cout<<"\n Enter how many matrixes to multiply ";
 cin>>nnn;

 if(nnn>NMAX || nnn ==1 )
 {
	cout<<"\n max allowed matrixes "<<NMAX;
	return;
 }

 for(int h=0;h<=nnn;h++)
	cin>>dims[h];
*/

 /******** create table **************/
 //for s=0 mii = -1
 for(int i=0;i<nnn;i++)
	  matrix[i][i] = 0;

 //s=1
 for(i=1;i<nnn;i++)
 {
	  matrix[i-1][i] = dims[i-1] * dims[i] * dims[i+1];
 }

 for(int s=2;s<nnn;s++)
 {

	for(int i=0;i<nnn-s;i++)
	{
	    minval = matrix[i][i]+matrix[i+1][i+s]+dims[i]*dims[i+1]*dims[i+1+s];

	    minlli = i;
	    minllj = i;
	    minrri = i+1;
	    minrrj = i+s;

	    for(int k=i+1;k<i+s;k++)
	    {//find min
		tempval = matrix[i][k]+matrix[k+1][i+s]+dims[i]*dims[k+1]*dims[i+1+s];
		if( tempval  < minval)
		{
		 minval = tempval;
		    minlli = i;
		    minllj = k;
		    minrri = k+1;
		    minrrj = i+s;
		}
	    }
	   matrix[i][i+s] = minval;
	   sol[i][i+s].minlli = minlli;
	   sol[i][i+s].minllj = minllj;
	   sol[i][i+s].minrri = minrri;
	   sol[i][i+s].minrrj = minrrj;
	}
  }
  /**********end of create table ***********/

  cout<<"The minimum calculation required is "<<matrix[0][nnn-1];
  cout<<"\n";
  dispresult(sol[0][nnn-1].minlli,sol[0][nnn-1].minllj,sol[0][nnn-1].minrri,sol[0][nnn-1].minrrj);

 getch();
}



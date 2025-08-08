/*
  Make change of money......
  user will enter total money.. the program need to find change of money so
  that the number of coins is minimum....

  The program follows greedy method...
  LOGIC:
	 Apply the max valued and next max valued coin as change first
	 if possible so that number of coins gets minimum...

  Applying greedy method here results in limitation here...
     * it doesn't give solution at all in some situation eventhough available.
     * It doesn't give best solution always.
*/

#include <stdio.h>
#include <conio.h>
#include <iostream.h>

#define MAXC 10
void main()
{
 clrscr();
 int avail_values[MAXC];
 int nvalues,tmoney;
 cout<<"\n Enter available valued coins .... ";
 cout<<"\n How much distinct valued coin available? ";
 cin>>nvalues;
 if(nvalues>MAXC)
 {
  cout<<"\nmaximum distinct valued coin allowed are "<<MAXC;
  return;
 }

 cout<<"\n Enter coin values in ascending order ";
 for(int i=0;i<nvalues;i++)
 {
	cin>>avail_values[i];
 }

 cout<<"\n Enter total money to be exchanged ";
 cin>>tmoney;

 int money=tmoney;
 i=nvalues-1;
 int rarr[MAXC]={0};
 while(1)
 {
	if(money>=avail_values[i])
	{
		rarr[i] = money / avail_values[i];
		money = money - (rarr[i]*avail_values[i]);
		if(money==0)
		{
			break;
		}
	}
	if(money<avail_values[0])
	{
		cout<<"\n Solution not available .."
			    <<"fails at money "<<money;
			break;
	}
   i--;
 }

 cout<<"\n COIN VALUE "<<"\t Number of coins ";
 int totalcoins=0;
 for(i=nvalues-1;i>=0;i--)
 {
	cout<<"\n"<<avail_values[i]<<"\t\t\t"<<rarr[i];
	totalcoins+=rarr[i];

 }
 cout<<"\n Total coins used "<<totalcoins;


 getch();
}
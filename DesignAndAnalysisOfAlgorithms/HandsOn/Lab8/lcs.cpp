/* Find monotically increasing subsequence from string S */

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>

enum DIR {HORIZONTAL,VERTICAL,DIAGONAL};
struct ELE
{
 int dcount;
 enum DIR dir; //default horizontal
};

struct ELE array[27][27];

void main()
{

 char istr1[27];//="0ABCDEF";
 char istr2[27];//="0ADCBBDF";
 char aux[27];
 char lcs[27];
 int choice;

 int l1,l2;
 enum DIR ddir = HORIZONTAL;

 clrscr();

 cout<<"\n Press 1 for finding LCS of two string "
     <<"\n 	 2 for finding Monotonically increasing subsequence of a string"
     <<"\n any other to exit ";
 // cout<<"\n Limitation : It doesnt find subsequence for both cases lower...upper;
 cin>>choice;
 if(choice == 1)
 {
   cout<<"\n type in UPPER CASE ONLY ";
   cout<<"\n Enter string1 ";
   cin>>istr1;
   strcpy(aux,"0");
   strcat(aux,istr1);
   strcpy(istr1,aux);

   cout<<"\n Enter string2";
   cin>>istr2;
   strcpy(aux,"0");
   strcat(aux,istr2);
   strcpy(istr2,aux);

  l1 = strlen(istr1);
  l2 = strlen(istr2);

  if(l1>l2) //program requires istr1 to be shorter
  {
    strcpy(aux,istr1);
    strcpy(istr1,istr2);
    strcpy(istr2,aux);
  }
 }
 else if (choice==2)
 {
   cout<<"\n Enter string1 ";
   cin>>istr2;
   l2 = strlen(istr2);

   strcpy(aux,"0");
   strcat(aux,istr2);
   strcpy(istr2,aux);
   l2++;

   //generate monotically other string
   //find max char symbol in input...
	char max='A';
	   for(int p=0;p<l2;p++)
	   {
		if(istr2[p]>'A')
		  max = istr2[p];
	   }

	   p=-1;
	   char t='A';
	   while(1)
	   {
		istr1[++p] = t;
		t++;
		if(t==max+1)
		{
			istr1[++p]=NULL;
			break;
		}
	   }
	   l1 = p+1;
   strcpy(aux,"0");
   strcat(aux,istr1);
   strcpy(istr1,aux);

 }
 else
 {
	cout<<"\n Have a nice day";
	return;
 }

 //make first row with count 0
 for(int j=0;j<l2;j++)
    array[j][0].dcount = 0;
 //make first column with count 0
 for(int i=0;i<l1;i++)
    array[0][i].dcount=0;


 //generating 2d array...
 for(i=1;i<l1;i++)
 {
   for(j=1;j<l2;j++)
   {
      if(istr1[i]==istr2[j])
      {
	array[i][j].dcount = array[i-1][j-1].dcount + 1;
	array[i][j].dir = DIAGONAL;
      }//end of if both string are same
      else if(array[i][j-1].dcount > array[i-1][j].dcount) // hor left > above
      {
	array[i][j].dcount = array[i][j-1].dcount;
	array[i][j].dir = HORIZONTAL;
      }//end of hor left > above
      else if(array[i-1][j].dcount > array[i][j-1].dcount) // above > hor left
      {
	array[i][j].dcount = array[i-1][j].dcount;
	array[i][j].dir = VERTICAL;
      }//end of above > hor left
      else // both are equal
      {
	array[i][j].dcount = array[i][j-1].dcount;
	array[i][j].dir = ddir;//HORIZONTAL
      }//end of both are equal
    }//end of j for
 }//end of i for


 //print lcs
 //lets have shortest string as istr1
 int co=-1;
 i=l1-1;
 j=l2-1;
 while(1)
 {

  if( array[i][j].dir == DIAGONAL)
  {
    lcs[++co] = istr1[i];
    i--;
    j--;
  }
  else if(array[i][j].dir == HORIZONTAL)
  {
	j--;
  }
  else
  {
	i--;
  }
  if(i==0 || j==0)
    break;
 }// end of while1

 lcs[++co] = NULL;

 strrev(lcs);

 cout<<"\n Longest common subsequence "<<lcs;

 getch();
}//end of main
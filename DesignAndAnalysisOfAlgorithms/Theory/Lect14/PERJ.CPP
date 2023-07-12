#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 10

struct data
{
 int array[MAX];
 int st;//starts from 0
 int ntimes;
 int size;
};

void display(struct data &d,unsigned int nofp)
{
	cout<<endl<<"Per#"<<setw(7)<<nofp<<">> ";

	for(int i=0;i<d.size;i++)
		cout<<setw(2)<<d.array[i]<<" ";

}
void permutation(struct data d)
{
	static unsigned int np=0;
	if(d.ntimes==1)
	{
		np++;
		display(d,np);
	}
	else
	{
		struct data tempd;

		for(int count=0;count<d.ntimes;count++)
		{
			int t;
			tempd = d;
			t = tempd.array[tempd.st];
			tempd.array[tempd.st] = tempd.array[tempd.st+count];
			tempd.array[tempd.st+count]=t;

			tempd.st++;
			tempd.ntimes--;

			permutation(tempd);
		}
	}
}
int main()
{
 
 struct data d;
 int s;//size
 cout<<"\n Integer set's permutations... ";
 cout<<"\n How many elements...... (atmost 10 supported as of static array)";
 cin>>s;

 cout<<"\n";
 if(s>10)
 {
	cout<<"\n Max 10 elements supported ... try again for less.";
	exit(0);
 }
 cout<<"\n Enter elemets ";
 for(int i=0;i<s;i++)
    cin>>d.array[i];

 d.st =0;
 d.ntimes= s;
 d.size=s;

 permutation(d);

 return 0;
}
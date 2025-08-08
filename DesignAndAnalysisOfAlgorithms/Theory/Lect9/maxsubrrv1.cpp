#include <iostream>
using namespace std;
int main()
{
	int arraydiff[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int n=sizeof(arraydiff)/sizeof(int);
	int i,j, k;
	int summation=0;
	int gmax;
	int start, end;
	cout<<"Total diffs "<<n<<endl;
	
	//To have first known global maximum value
	for(i=0;i<n;i++)
	{
		summation+=arraydiff[i];
	}
	gmax=summation;
	start=0;
	end=n-1;
	
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			summation=arraydiff[i];
			for(k=i+1;k<=j;k++)
				summation+=arraydiff[k];
			cout<<"start "<<i<<" end "<<j<<" summation is "<<summation<<endl;
			if(summation>gmax)
			{
				gmax=summation;
				start=i;
				end=j;
			}
		}
		cout<<endl<<endl;
	}
	cout<<"Summation of max subarra "<<gmax<<endl;
	cout<<"Start: "<<start<<endl;
	cout<<"End: "<<end<<endl;
}
	

//Recursive implementation of NQueens using backtracking.
//Here, the name of identifiers are attached with appropriate meaning of the same in addition to book authors i,j,k,etc.
//I personally believe that till when possible having meaningful names give better understanding and less error prone.
//Only in cases where one identifier may have more than one correct meaning, it might not be named appropriately. Or it depends if some programmer are more comfortable with i,j,k, etc.

#include <iostream>
#include <cmath>
#include <iomanip>
#define MAX 50
using namespace std;
int result[MAX]={0};
int totalSolutions=0;
int linenumber=0;
void displaytabs(int t)
{
    int i;
    for(i=0;i<t;i++)
    {
        cout<<"\t";
    }
}
void display_result(int n)
{
    int r,c;
    cout<<"\n"<<linenumber++<<" -------------\n";
    cout<<"\n"<<linenumber++<<"  Displaying solution number # "<<++totalSolutions<<"\n";
    for(r=1;r<=n;r++)
    {
        for(c=1;c<=n;c++)
        {
            if(result[r]==c)
                cout<<"1"<<"\t";
            else
                cout<<"0"<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n"<<linenumber++<<" -------------\n";
}
bool place(int rowK, int columnI)
{
    int rJ;
    for(rJ=1;rJ<=(rowK-1);rJ++)
    {
        if(result[rJ]==columnI)//column check
        {
            cout<<"\n"<<linenumber++<<"  Queen# "<<rJ<<" attacking columnwise being at "<<result[rJ]<<" while trying for column "<<columnI<<"\n";
            return false;
        }
        if( ( (rowK-columnI)==(rJ-result[rJ]) ) || ((rJ+result[rJ])==(rowK+columnI))) //F1
        //if(abs(result[rJ]-columnI)==abs(rJ-rowK))//F2
        // Formula F2 means the same as F1 based on maths. for points (rJ,result[rJ]) and (rowK,columnI). Move left right of equal terms.
        // result[rJ]-columnI = rJ - rowK    based on F1.1
        // result[rJ]-columnI = rowK - rJ = - rJ + rowK = -(rJ-rowK)  based on F1.2. Meaning...
        // abs(result[rJ]-columnI) = abs(rJ-rowK) F2 
        {
            cout<<"\n"<<linenumber++<<" Queen# "<<rJ<<" attacking diagonally being at "<<result[rJ]<<" while trying for column "<<columnI<<"\n";
            return false;
        }
            
    }     
    return true;

}
void NQueens(int rowK, int n)
//Here, n indicates total number of queens to be arranged. starting from row numbered row.
{
    int static sdepth=0;
    sdepth++;
    int columnI;      
    cout<<"\n"<<linenumber++<<" -------------- Depth START "<<sdepth<<"-----------"<<"\n";  
    for(columnI=1;columnI<=n;columnI++)
    {
        displaytabs(sdepth);cout<<"Attempting to place queen# "<<rowK<<" at column "<<columnI<<"\n";
        if(place(rowK,columnI))
        {
            displaytabs(sdepth);cout<<"Placed queen# "<<rowK<<" at column "<<columnI<<"\n";
            result[rowK]=columnI;
            if(rowK==n)
            {
                display_result(n);
                // exit(0); Enable this, if only wants to see first solution.
            }
            else
            {
                displaytabs(sdepth);cout<<"Arrangement starting for queen "<<rowK+1<<"\n";
                NQueens(rowK+1,n);
                displaytabs(sdepth);cout<<"Arrangement ending for queen "<<rowK+1<<"\n";
            }
            
        }
    }
    cout<<"\n"<<linenumber++<<" -------------- Depth END "<<sdepth<<"-----------"<<"\n";  
    sdepth--;
    
}

int main()
{   
    int n;
    cout<<"\n Enter n (1-"<<MAX<<")";
    cin>>n;
    cout<<"\n"<<linenumber++<<" Arrangement starting for queen  "<<"1"<<"\n";
    NQueens(1,n);
    cout<<"\n"<<linenumber++<<" Arrangement ending for queen"<<"1"<<"\n";
    if(!totalSolutions)
    {
        cout<<"\n"<<linenumber++<<" Solution does not exist for n value "<<n<<"\n";
    }
    else
    {
        cout<<"\n"<<linenumber++<<" Generated and displayed total "<<totalSolutions<<" solutions."<<"\n";
    }
    return 0;
}
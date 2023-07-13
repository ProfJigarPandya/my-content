#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int **graph=NULL;
int n;
int *result=NULL;
bool isSuitableColor(int currentColor,int levelNodeNumber);
void display_result();
int mGraphColoringRec(int levelNodeNumber,int totalColors);

int main()
{
    ifstream fis;
    fis.open("C:\\Users\\jigar\\OneDrive\\Documents\\DAA\\prog\\DAA\\inputGraphColoring.txt",std::ios_base::in);
    if(fis.fail())
    {
        cout<<"Data file could not be opened";
        return 1;
    }

    do
    {
    int m;
    fis>>m;
    cout<<"\nFor m colors "<<m;
    fis>>n;
    cout<<"\nFor n nodes "<<n;
    graph=new int*[n+1];
    result=new int[n+1];
    int i;
    for(i=0;i<=n;i++)
    {
        graph[i]=new int [n+1];
    }
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=n;c++)
        {
            fis>>graph[r][c];
        }
    }


    cout<<"\nGraph data\n";
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=n;c++)
        {
            cout<<graph[r][c]<<"\t";
        }
        cout<<"\n";
    }


    cout<<"\nGraph Coloring....\n";
    int totalSolutoins=mGraphColoringRec(1,m);
    if(totalSolutoins)
    {
        cout<<"\nTotal solutoins found are "<<totalSolutoins;
    }
    else
    {
        cout<<"\nNo solution found";
    }
    
    for(i=0;i<=n;i++)
    {
        delete [] graph;
    }
    delete graph;

    }while(!fis.eof());
    fis.close();
    cout<<"\n Have a nice day.";
    return(0);
}
int mGraphColoringRec(int levelNodeNumber,int totalColors)
{
    static int totalSolutions=0;
    if(levelNodeNumber==1)//required for reset over next example run
        totalSolutions=0;

    int currentColor;
    for(currentColor=1;currentColor<=totalColors;currentColor++)
    {
        if(isSuitableColor(currentColor,levelNodeNumber))
        {
            result[levelNodeNumber]=currentColor;
            if(levelNodeNumber==n)
            {
                totalSolutions++;
                display_result();
            }
            if(levelNodeNumber<n)
              mGraphColoringRec(levelNodeNumber+1,totalColors); 
                              
        }


    }//end of for colors
    return totalSolutions;
}
bool isSuitableColor(int currentColor,int levelNodeNumber)
{
    int node;
    for(node=1;node<levelNodeNumber;node++)
    {
        if(result[node]==currentColor)//current color is taken by node
        {
            if(graph[node][levelNodeNumber])//both nodes are adjacent; connected.
            {
                return false;
            }
        }
    }
    return true;
}

void display_result()
{
    cout<<"\n";
    for(int i=1;i<=n;i++)
        cout<<result[i]<<"\t";
}
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int **graph=NULL;
int n;
int *result=NULL;
int isFeasible( int levelNodeNumber,int startNode);
void display_result();
int hamiltonianCycleRec(int levelNodeNumber);

int main()
{
    ifstream fis;
    fis.open("C:\\Users\\jigar\\OneDrive\\Documents\\DAA\\prog\\DAA\\inputHamiltonianCyc.txt",std::ios_base::in);
    if(fis.fail())
    {
        cout<<"Data file could not be opened";
        return 1;
    }

    do
    {
    fis>>n;
    cout<<"\nFor n nodes "<<n;
    graph=new int*[n+1];
    result=new int[n+1];
    int i;
    for(i=0;i<=n;i++)
    {
        graph[i]=new int [n+1];
        result[i]=0;
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


    cout<<"\nHamiltonian Cycle ....\n";
    int totalSolutoins=hamiltonianCycleRec(1);
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
int hamiltonianCycleRec(int levelNodeNumber)
{
    
    static int totalSolutions=0;
    if(levelNodeNumber==1)//required for reset over next example run
        totalSolutions=0;

    int startNode;
    for(startNode=1;startNode<=n;startNode++)
    {
        // Starting the route from. Source of the cycle detection.
        if(levelNodeNumber==1)
        {
            result[levelNodeNumber]=startNode;
            hamiltonianCycleRec(levelNodeNumber+1); 
        }
        else
        {
            if(isFeasible(levelNodeNumber, startNode))
            {
                result[levelNodeNumber]=startNode;
                if(levelNodeNumber==n)
                {
                    if(graph[result[levelNodeNumber]][result[1]])//There is an edge between last and first creating cycle
                    {
                        totalSolutions++;
                        display_result();
                    }
                }
                if(levelNodeNumber<n)
                    hamiltonianCycleRec(levelNodeNumber+1); 
            }
        }
    }//end of for columns
    return totalSolutions;
}
int isFeasible( int levelNodeNumber,int startNode)
{

    if(graph[result[levelNodeNumber-1]][startNode]) // if node to be added is connected to previous
    {
        for(int node=1;node<levelNodeNumber;node++)
        {
            if(result[node]==startNode)//node forms a intermediate cycle
                return 0;
        }
        return 1;
    }
    return 0;//no connection
}

void display_result()
{
    cout<<"\n";
    for(int i=1;i<=n;i++)
        cout<<result[i]<<"\t";
}
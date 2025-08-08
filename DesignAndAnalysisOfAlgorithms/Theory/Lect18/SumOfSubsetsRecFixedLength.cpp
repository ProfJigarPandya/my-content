#include <iostream>
#include <iomanip>

using namespace std;
int weights[]={0,11,13,24,7};//Initialize weights here. location 0 is ignore. example1.
//int weights[]={0,5,7,10,12,15,18,20};//Initialize weights here. location 0 is ignore. example2.
//int weights[]={0,10, 7, 5, 18, 12, 20, 15};//Initialize weights here. location 0 is ignore. example3. unsoreted values from example2.
//int weights[]={0,3, 34, 4, 12, 5, 2};//Initialize weights here. location 0 is ignore. example4. 
//int weights[]={0,5, 10, 12, 13, 15, 18};//Initialize weights here. location 0 is ignore. example5.
int n=(sizeof(weights)/sizeof(int)) - 1;//0 is not counted.
int *result=new int[n+1];//location 0 is ignore.
bool weightcheckGreen(int attemptpos,bool isAdded, int match_sum);
bool weightMatching(int match_sum);
int rsumofsubsetsFixedLen(int attemptpos,int match_sum); 
void display_weights();
void display_result();
int main()
{
    int match_sum=31;// example1. Answer 0011;1101;
    //int match_sum=35;//example2. Answer 
    /*
    5       7       10      12      15      18      20
    0       0       0       0       1       0       1
    0       1       1       0       0       1       0
    1       0       0       1       0       1       0
    1       0       1       0       0       0       1
    */
    //int match_sum=35;//example3.
    /*
    10      7       5       18      12      20      15
    0       0       0       0       0       1       1
    0       0       1       1       1       0       0
    1       0       1       0       0       1       0
    1       1       0       1       0       0       0
    */
    //int match_sum=9;//example 4
    /*
    3       34      4       12      5       2
    0       0       1       0       1       0
    1       0       1       0       0       1
    */
    
    //int match_sum=30;//Example4. No solution case.
    //int match_sum=0;
    //int match_sum=30;//Example5.
    /*
    Expected total weight 30
5       10      12      13      15      18
0       0       1       0       0       1
1       0       1       1       0       0
1       1       0       0       1       0
    */
    int rescount;
    cout<<"\nWelcome.";
    cout<<"\nExpected total weight "<<match_sum;
    display_weights();
    rescount=rsumofsubsetsFixedLen(1,match_sum);
    if(!rescount)
    {
        cout<<"\n No solution exist.";
    }  
    else
    {
        cout<<"\n Total "<<rescount<<" number of solutions found";
    }
    cout<<"\nHave a nice day.";
    return 0;
}

int rsumofsubsetsFixedLen(int attemptpos,int match_sum)
{
    static int resultcount=0;
    int dire;
    for(dire=0;dire<2;dire++)
    {
        if(weightcheckGreen(attemptpos, dire, match_sum))
        {
            if(dire)//1
            {
                result[attemptpos]=1;
            }
            else//0
            {
                result[attemptpos]=0;
            }


            if((attemptpos==n))
            {
                if(weightMatching(match_sum))
                {
                    resultcount++;
                    display_result();
                }
            }
            else
            {
                rsumofsubsetsFixedLen(attemptpos+1,match_sum);
            }

            if(dire)//1 - reset before backtracking
            {   
                result[attemptpos]=0;
            }
        }
    }
    return resultcount;
}
void display_weights()
{
    int i;
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
        cout<<weights[i]<<"\t";
    }

}

void display_result()
{
    int i;
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
        cout<<result[i]<<"\t";
    }
}
bool weightcheckGreen(int attemptpos,bool isAdded, int match_sum)
{
    if(!isAdded)//if this object is not needed to be selected. Exploring 0 side branch.
        return true;
    
    //Exploring 1 side branch
    if(weights[attemptpos]>match_sum)//No point if weight is greater than total required to be matched.
        return false;

    int totalWSoFar=0;
    for(int i=1;i<attemptpos;i++)
    {
        if(result[i])  
        {
            totalWSoFar+=weights[i];
        }
    }   
    if((totalWSoFar+weights[attemptpos])<=match_sum)
        return true;
    else
        return false;
}
bool weightMatching(int match_sum)
{
    int totalWSoFar=0;
    for(int i=1;i<=n;i++)
    {
        if(result[i])  
        {
            totalWSoFar+=weights[i];
        }
    }   
    if(totalWSoFar==match_sum)
        return true;
    else   
        return false;
}
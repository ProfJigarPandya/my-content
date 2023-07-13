//Incomplete.
#include <stdio.h>
#include <stdlib.h>

int nqueensol(int n,int result[]);//The array is one more element size. 0th location unused.
int columncheck(int result[],int queen, int possibleloc);//true if crossing any columns
int diagonalcheck(int result[],int queen, int possibleloc);//true if crossing any diagonals
int main()
{
    int n=10;
    int i;
    int status=-1;
    int *result=(int *) malloc ((n+1) * sizeof(int));
    if(!result)
    {
        printf("\nCould not allocate memory");
        exit(1);
    }
    for(i=0;i<=n;i++)
        result[i]=0;
    printf("Welcome to n-queen problem solution : %d ",n);
    status=nqueensol(n, result);
    if(!status)//no solutions found
    {
        printf("\n No solutions found for the value of n %d ",n);
    }
    return 0;
}
int nqueensol(int n,int result[])//The array is one more element size. 0th location unused.
{
    int i,j;
    int queen=1;
    int possibleloc=-1;
    int noSolution=1;//Assume that there are no solutions.
    while(queen<=n)//place n queens
    {
        possibleloc=result[queen]+1; //Start from 1 or 1 more than previous success
        while(possibleloc<=n)//judge possible loc
        {
             //Check columns cross and diagonal cross
             if  ((columncheck(result,queen, possibleloc)) || (diagonalcheck(result,queen, possibleloc))) // if crossed either, try next location for current queen
             {
                    possibleloc++;
                    continue;       
             }
             else//Not crossed
             {
                 result[queen]=possibleloc;
                 break;
             }
        }//judge possible loc
        if(possibleloc==n+1)//possible loc not found for queen
        {
            if(result[1]==n)//first queen and last possible loc. No more backtracking. Here where I still need to work. I am seeing a flaw.
            {
                break; 
            }
            else // backtracking possile
            {
                    printf("\n Backtracking from queen %d",queen);
                    //reset this queen's attempt
                    result[queen]=0;
                    //go back to previous queen
                    queen-=1;
                    
            }
        }    
        else //possible location is found
        {
            printf("\n Possible location found at %d for queen %d",possibleloc, queen);
            queen++; //go for next queen
        }
    }//place n queens
    if(queen==n+1)//display one result
    {
        printf("\n One of the solution for %d queens arrangement ",n);
        printf("\n");
        for(i=1;i<=n;i++)
        {
            printf("%d\t",result[i]);
        }
        printf("\n\n\n\n");
        for(i=1;i<=n;i++)
        {
            printf("%d\t",i);
            for(j=1;j<=n;j++)
            {
                if(j==result[i])
                {
                    printf(" 1  \t");
                }
                else
                {
                    printf("*****\t");
                }
                
            }
            printf("\n");
        }           
        return 1;
    }
    else
    {
        return 0;
    }  
}
int columncheck(int result[],int queen, int possibleloc)//true if crossing any columns
{
    int prevqueen=-1;
    for(prevqueen=1;prevqueen<queen;prevqueen++)
    {
        if(result[prevqueen]==possibleloc)
        {
            printf("\nQueen# %d is crossing with previous queen# %d columnwise while checking for %d possible location",queen,prevqueen,possibleloc);
            return 1;//crossing column wise with queen number prevqueen
        }
    }
    return 0;//Not crossing column wise
}

int diagonalcheck(int result[],int queen, int possibleloc)//true if crossing any diagonals
{
    int prevqueen=-1;
    int queenminmodvalue=-1;
    int queenmaxvalue=-1;
    int prev_queenminmodvalue=-1;
    int prev_queenmaxvalue=-1;

    //calcualte current queen minmod value
    queenminmodvalue=(possibleloc-queen);        
    
    //calculate current queen max value
    queenmaxvalue=(possibleloc+queen);        

    for(prevqueen=1;prevqueen<queen;prevqueen++)
    {
        //calculate prevqueen's minmod value
        prev_queenminmodvalue=(result[prevqueen]-prevqueen);        

        //calculate prevqueen's max value
        prev_queenmaxvalue=(result[prevqueen]+prevqueen);        

        if((prev_queenminmodvalue==queenminmodvalue) || (prev_queenmaxvalue==queenmaxvalue))//if either min or max matches then cross diagonal
        {
            printf("\nQueen# %d is crossing with previous queen# %d diagonally while checking for %d possible location",queen,prevqueen,possibleloc);
            return 1;//crossing column wise with queen number prevqueen
        }
    }
    return 0;//Not crossing column wise
}

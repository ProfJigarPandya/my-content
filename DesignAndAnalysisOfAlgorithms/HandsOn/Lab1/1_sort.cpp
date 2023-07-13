#include <iostream>
void bubblesort(int len,int dataarr[],int direction=1)
{
    int temp;
    int swapflag=1;//assume swap will be required

    if(direction==1)//ascending. default.
        {
           for(int pass=1;(pass<len) && (swapflag==1);pass++)
            {
               swapflag=0;
                for(int i=0;i<(len-pass);i++)
                {
                        if(dataarr[i]>dataarr[i+1])
                        {
                            temp = dataarr[i];
                            dataarr[i]=dataarr[i+1];
                            dataarr[i+1]=temp;
                            swapflag=1;
                        }
                }
            }
        }
}

void insertionsort(int len,int dataarr[], int direction=1)
{
    int holder,sorti;
    if(direction==1)//ascending. default.
    {
        for(int entryi=1;entryi<len;entryi++)
        {
            holder=dataarr[entryi];
            sorti=entryi-1;
            while((sorti>=0)&&(holder<dataarr[sorti]))
            {
                    dataarr[sorti+1]=dataarr[sorti];
                    sorti--;
            }
            dataarr[sorti+1]=holder;
        }
    }
}

void smartinsertionsort(int len,int dataarr[], int direction=1)
{
    int holdertobein,holderzero,sorti;
    if(direction==1)//ascending. default.
    {
        for(int entryi=1;entryi<len;entryi++)
        {
            holderzero=dataarr[0];//backup1
            holdertobein=dataarr[entryi];//backup2
            sorti=entryi-1;
            dataarr[0]=holdertobein;//This will confirm that loop will stop for sure and avoids check sorti>=0
            while((holdertobein<dataarr[sorti]))
            {
                    dataarr[sorti+1]=dataarr[sorti];
                    sorti--;
                
            }
            dataarr[0]=holderzero;//restore1
            if(holdertobein<dataarr[sorti]) 
            {
                dataarr[sorti+1]=dataarr[sorti];
                sorti--;
            }
            
            dataarr[sorti+1]=holdertobein;//restore2 or at stored required sorted place
        }
    }
}

void twowaymergesort(int arr1left, int arr1right,int arr2left, int arr2right, int dataarr[])//0,5,6,10
{
    int memlen=(arr1right-arr1left+1)+(arr2right-arr2left+1);
    int *buffer = new int [memlen];
    
    int i,j,k=0,l=0;
    for(i=arr1left, j=arr2left; (i<=arr1right)  && (j<=arr2right); )
    {
        if(dataarr[i]<dataarr[j])
        {
            buffer[k++]=dataarr[i++];
        }
        else
        {
            buffer[k++]=dataarr[j++];
        }
    }
    
    while(i<=arr1right)
    {
         buffer[k++]=dataarr[i++];
    }
    while(j<=arr2right)
    {
         buffer[k++]=dataarr[j++];
    }
    
    //overwrite original with sorted data
    
    for(i=0;i<(arr1right-arr1left+1);i++)
    {
        dataarr[arr1left+i]=buffer[l++];
    }
    for(j=0;j<(arr2right-arr2left+1);j++)
    {
        dataarr[arr2left+j]=buffer[l++];
    }
    
    
    delete [] buffer;
}

void nwaymergesort(int dataarr[],int start,int end)
{
    int middle;
    if(start<end)
    {
        middle=(end+start)/2;
        nwaymergesort(dataarr,start,middle);
        nwaymergesort(dataarr,middle+1,end);
        twowaymergesort(start,middle,middle+1,end,dataarr);
    }
    
}

int main() {
    int len;
    std::cin>>len;
    int *dataarr = new int[len];
    for(int i=0;i<len;i++)
        std::cin>>dataarr[i];

    //bubblesort(len,dataarr);
    //insertionsort(len,dataarr);
    //smartinsertionsort(len,dataarr);
    nwaymergesort(dataarr,0,len-1);

    for(int i=0;i<len;i++)
        std::cout<<dataarr[i]<<" ";
    delete []dataarr;

    return 0;
}

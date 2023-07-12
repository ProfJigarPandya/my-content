#include <iostream>
void mergetwosortedarrays(int arr1left, int arr1right,int arr2left, int arr2right, int dataarr[])
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

void mergesort(int dataarr[],int start,int end)
{
    int middle;
    if(start<end)
    {
        middle=(end-start)/2;
        mergesort(dataarr,start,middle);
        mergesort(dataarr,middle+1,end);
        mergetwosortedarrays(start,middle,middle+1,end,dataarr);
    }
    
}

int main() {
    int len;
    std::cin>>len;
    int *dataarr = new int[len];
    for(int i=0;i<len;i++)
        std::cin>>dataarr[i];

    mergesort(dataarr,0,len-1);

    for(int i=0;i<len;i++)
        std::cout<<dataarr[i]<<" ";
    delete []dataarr;

    return 0;
}

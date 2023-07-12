#include <iostream>
void sortdesc(int len,int arr[][2])
{
    for(int pass=1;pass<=(len-1);pass++)
    {
        for(int i=0;i<(len-pass);i++)
        {
            if(arr[i][0]<arr[i+1][0])
            {
                int t;
                t=arr[i][0];
                arr[i][0]=arr[i+1][0];
                arr[i+1][0]=t;
               
                t=arr[i][1];
                arr[i][1]=arr[i+1][1];
                arr[i+1][1]=t;
                
            }
        }
    }
}

int tendering(int len,int availcoins[][2],int tendercoins[][2],int amount)
{
    int countdeno=-1;
    int denoind=0;
    while((amount>0) && (denoind<len) )
    {
         if(availcoins[denoind][0]*availcoins[denoind][1] == amount)//amount is equal current deno total
         {
             tendercoins[++countdeno][0]=availcoins[denoind][0];
             tendercoins[countdeno][1]=availcoins[denoind][1];
             return countdeno+1;
         }
        else if(availcoins[denoind][0]*availcoins[denoind][1] < amount) //amount is more than current deno total
        {    
                 tendercoins[++countdeno][0]=availcoins[denoind][0];
                 tendercoins[countdeno][1]=availcoins[denoind][1];
                 amount=amount-(availcoins[denoind][0]*availcoins[denoind][1]);
        }
        else//amount is less than current deno total
        {   
                 if( (amount%availcoins[denoind][0]) == 0)
                 {
                     tendercoins[++countdeno][0]=availcoins[denoind][0];
                     tendercoins[countdeno][1]=amount/availcoins[denoind][0];
                     return countdeno+1;
                 }    
                 else
                 {
                    if(amount>availcoins[denoind][0])
                    {
                        tendercoins[++countdeno][0]=availcoins[denoind][0];
                        tendercoins[countdeno][1]=amount/availcoins[denoind][0];
                        amount=amount-availcoins[denoind][0]*(amount/availcoins[denoind][0]);
                    }
                 }
        }
        denoind++;
    }
    if (amount==0)
        return countdeno+1;
    else
        return -1;    
}
int main() {
    int nounideno;
    std::cin>>nounideno;
    int availcoins[nounideno][2]={0};
    int tendercoins[nounideno][2]={0};
    
    
    for(int i=0;i<nounideno;i++)
    {
        //std::cout<<tendercoins[i][0]<<" "<<tendercoins[i][1]<<std::endl;
         std::cin>>availcoins[i][0]>>availcoins[i][1];
    }
    int totamount;
    std::cin>>totamount;
    
    sortdesc(nounideno,availcoins);
    
    int ret=-2;
    ret=tendering(nounideno,availcoins,tendercoins,totamount);
    
    if(ret!=-1)
    {   
        std::cout<<ret<<std::endl;
        for(int i=0;i<ret;i++)
        {
            std::cout<<tendercoins[i][0]<<" "<<tendercoins[i][1]<<std::endl;
        }
    }
    else
        std::cout<<ret;
    
    
    return 0;
}

#include<stdio.h>
struct item
{
    int no;
    float weight;
    float profit;
    float profitbyweight;
};

int main()
{
    printf("Enter the Number of Items\n");
    int n;
    scanf("%d",&n);
    struct item arr[n],i;
    printf("Enter Profit and Weight of each Item:-\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&arr[i].profit,&arr[i].weight);
        arr[i].no=i;
        arr[i].profitbyweight=arr[i].profit/arr[i].weight;
    }
    int weight;
    printf("Enter Total Weight of Knapsack\n");
    scanf("%d",&weight);
    float fractionsarr[n];
    for(int i=0;i<n;i++)
        fractionsarr[i]=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[j].profitbyweight<arr[j+1].profitbyweight)//SWAP
            {
                int x=arr[j].no;
                arr[j].no=arr[j+1].no;
                arr[j+1].no=x;

                float f=arr[j].profit;
                arr[j].profit=arr[j+1].profit;
                arr[j+1].profit=f;

                f=arr[j].weight;
                arr[j].weigth=arr[j+1].weigth;
                arr[j+1].weigth=f;

                f=arr[j].profitbyweight;
                arr[j].profitbyweight=arr[j+1].profitbyweight;
                arr[j+1].profitbyweight=f;
            }

        }
    }

}

#include<stdio.h>
int checkgood(int a[],int low,int high)
{
    int i,j,k;
    for(i=low;i<high;i++)
    {
        for(j=i+1;j<=high;j++)
        {
            for(k=low;k<=high;k++)
            {
                if(k!=i && k!=j && a[k]==a[i]+a[j])
                    return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n],x=1,i;
        for(i=0;i<n;i++)
        {
           if(i==0)
             a[i]=1;
           else
             a[i]=a[i-1]+1;
           while(checkgood(a,0,i)!=1 && a[i]<=500)
               a[i]++;
        }
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}

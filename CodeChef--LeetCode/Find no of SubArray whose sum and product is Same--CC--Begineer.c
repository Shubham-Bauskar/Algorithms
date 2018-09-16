#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n],i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int s,p,count=0,j,k;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                s=0;
                p=1;
                for(k=i;k<=j;k++)
                {
                    s+=a[k];
                    p*=a[k];
                }
                if(s==p)
                    count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

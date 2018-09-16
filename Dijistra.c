#include<stdio.h>
int main()
{
    printf("Enter no. of nodes in Graph:-\n");
    int n;
    scanf("%d",&n);
    int a[n][n],i,j;
    printf("Enter the Weight of Edges,if exits else 1000:-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter Source & Destination Vertex:-\n");
    int s,d;
    scanf("%d%d",&s,&d);
    int chosen[n],cost[n];
    for(i=0;i<n;i++)
    {
        chosen[i]=0;
        cost[i]=a[s][i];
    }
    chosen[s]=1;
    int k;
    for(k=1;k<=n-1;k++)
    {
        int t;
        int xv,min=100000;
        for(t=0;t<n;t++)
        {
            if(chosen[t]==0)
            {
                if(cost[t]<min)
                {
                    min=cost[t];
                    xv=t;
                }
            }
        }
        chosen[xv]=1;
        for(j=0;j<n;j++)
        {
            if(a[xv][j]!=1000)
            {
                if(cost[j]>cost[xv]+a[xv][j])
                    cost[j]=cost[xv]+a[xv][j];
            }
        }
    }
    printf("\nMINIMUM COST OF PATH FROM %d->%d =%d\n",s,d,cost[d]);
    return 0;
}


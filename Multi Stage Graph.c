#include<stdio.h>
void main()
{
    int n;
    printf("Enter Number of Nodes in Graph\n");
    scanf("%d",&n);
    int g[n][n],i,j;
    printf("Enter the Weight of Edge if exist, else -1\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    int cost[n];
    for(i=0;i<n;i++)
        cost[i]=0;
    int t;
    for(j=n-2;j>=0;j--)
    {
        int min=10000;
        for(t=0;t<n;t++)
        {
            if(g[j][t]!=-1)
            {
                if(min>g[j][t]+cost[t])
                    min=g[j][t]+cost[t];
            }
        }
        cost[j]=min;
    }
    printf("\nDISTANCE s->d is =%d",cost[0]);
}

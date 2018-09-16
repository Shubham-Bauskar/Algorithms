#include<stdio.h>
int main()
{
    printf("Enter no. of nodes in Graph:-\n");
    int n;
    scanf("%d",&n);
    int a[n][n],i,j;
    printf("Enter the Weight of Edges,if exits else 0:-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int chosen[n],near[n];
    for(i=0;i<n;i++)
    {
        chosen[i]=0;
        near[i]=-1;
    }
    int min=a[0][0],mi=0,mj=0; //Find minimum cost edge
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]<=min)
            {
                mi=i;
                mj=j;
                min=a[i][j];
            }
    int mincost=a[mi][mj];
    chosen[mi]=chosen[mj]=1;
    near[mi]=mj;
    near[mj]=mi;
    for(i=0;i<n;i++)
    {
        if(chosen[i]==0)
        {
            if(a[mi][i]<a[mj][j])
                near[i]=mi;
            else
                near[j]=mj;
        }
    }
    int k=1;
    while(k<=n-2)
    {
        int t;
        int xv;
        min=100000;
        for(t=0;t<n;t++)
        {
            if(chosen[t]==0)
            {
                if(a[t][near[t]]<min)
                {
                    xv=t;
                    min=a[t][near[t]];
                }
            }
        }
        chosen[xv]=1;  //Readjustment Phase
        for(j=0;j<n;j++)
        {
            if(chosen[j]==0)
            {
                if(a[xv][j]<a[j][near[j]])
                    near[j]=xv;
            }
        }
        mincost+=a[xv][near[xv]];
        k++;
    }
    printf("\nCOST OF MINIMUM SPANNING TREE=%d",mincost);
    return 0;
}

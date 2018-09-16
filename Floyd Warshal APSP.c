#include<stdio.h>
int main()
{
    printf("Enter no.of Nodes of an Undirected Graph:-\n");
    int n;
    scanf("%d",&n);
    int a[n][n],i,j,k;
    printf("Enter weight of Edge if exits, else 0:-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
    }
    printf("ALL PAIR SHORTEST PATH:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int n;
    printf("Enter Number of Nodes in a Graph:-\n");
    scanf("%d",&n);
    int a[n][n],i,j;
    printf("Enter 1 if there is an Edge From i->j else 0:-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int v[n];// Visited Status
    for(i=0;i<n;i++)
        v[i]=0;
    printf("Enter the Source && Destination Vertex:-\n");
    int s,d,foundflag=0;
    scanf("%d%d",&s,&d);
    int S[n],top=-1,x;
    S[++top]=s;
    printf("Nodes Visited till Now=");
    while(top!=-1)
    {
        // Pop that node check if it is equals to destination or not if equal break
        // If not Equal insert its adjacent nodes whose visited status is 0 to Stack
        x=S[top--];
        printf("%d ",x);
        v[x]=2;
        if(x==d)
        {
            foundflag=1;
            printf("\nTHERE IS A PATH FROM %d-->>%d",s,d);
            break;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(a[x][i]==1 && v[i]==0)// Adding the adjacent nodes to Stack whose visited status is False
                {
                    S[++top]=i;
                    v[i]=1;
                }
            }
        }
    }
    if(foundflag==0)
        printf("\n--NO PATH EXISTS\n");
    return 0;
}

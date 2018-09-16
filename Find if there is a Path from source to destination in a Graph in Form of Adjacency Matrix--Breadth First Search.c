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
    int Q[n],front=-1,rear=-1,x;
    Q[++rear]=s;
    ++front;
    printf("Nodes Visited till Now=");
    while(front!=-1)
    {
        // Pop that node check if it is equals to destination or not if equal break
        // If not Equal insert its adjacent nodes whose visited status is 0 to Queue
        x=Q[front++];
        printf("%d ",x);
        v[x]=2;
        if(front==rear+1)//Last element is Deleted
            front=rear=-1;
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
                if(a[x][i]==1 && v[i]==0)// Adding the adjacent nodes to Queue whose visited status is False
                {
                    Q[++rear]=i;
                    if(front==-1)
                        front=0;
                    v[i]=1;
                }
            }
        }
    }
    if(foundflag==0)
        printf("\n--NO PATH EXISTS\n");
    return 0;
}

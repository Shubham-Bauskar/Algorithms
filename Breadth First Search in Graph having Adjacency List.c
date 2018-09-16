#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int n;
    printf("Enter the Number of Nodes:-\n");
    scanf("%d",&n);
    printf("Enter the Number of Edges:-\n");
    int m;
    scanf("%d",&m);
    struct node *a[n];
    int i;
    for(i=0;i<n;i++)
        a[i]=NULL;
    printf("Enter the Edges u->v\n");
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        struct node *p=(struct node *)malloc(sizeof(struct node));// Adding u-->>v
        p->data=v;
        p->next=NULL;
        if(a[u]==NULL)
            a[u]=p;
        else
        {
            struct node *ptr=a[u];
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=p;
        }
        struct node *q=(struct node *)malloc(sizeof(struct node));// Adding v-->>u
        q->data=u;
        q->next=NULL;
        if(a[v]==NULL)
            a[v]=q;
        else
        {
            struct node *ptr=a[v];
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=q;
        }
    }
    printf("Graph in Form of Adjacency List:-\n");
    for(i=0;i<n;i++)
    {
        printf("%d-->>",i);
        if(a[i]==NULL)
            printf("NULL");
        struct node *ptr=a[i];
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("BREADTH FIRST SEARCH:-\n");
    int visited[n];// Hold the Visited Status
    for(i=0;i<n;i++)
        visited[i]=0; // 0=Not Processed 1=Waiting in Queue 2=Processed
    printf("Enter the Source && Destination Vertex:-\n");
    int s,d;
    scanf("%d%d",&s,&d);
    int queue[n],front=-1,rear=-1,temp,found=0;
    queue[++rear]=s;
    ++front;
    printf("Nodes Visited till Now=");
    while(front!=-1)
    {
        temp=queue[front++];
        if(front==rear+1)//Last Element is Deleted
            front=rear=-1;
        printf("%d ",temp);
        visited[temp]=2;
        if(temp==d)
        {
            printf("\nTHERE IS A PATH FROM %d-->>%d",s,d);
            found=1;
            break;
        }
        else // Put all the Adjacent nodes of Temp into the Queue whose visited status=0
        {
            struct node *ptr=a[temp];
            while(ptr!=NULL)
            {
                int x=ptr->data;
                if(visited[x]==0)
                {
                    queue[++rear]=x;
                    if(front==-1)
                        front=0;
                    visited[x]=1;
                }
                ptr=ptr->next;
            }
        }
    }
    if(found==0)
        printf("\nNO PATH EXISTS\n");
    return 0;
}

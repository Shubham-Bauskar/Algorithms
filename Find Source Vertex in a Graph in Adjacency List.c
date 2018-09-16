#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int n;
    printf("Enter Number of Projects:-\n");
    scanf("%d",&n);
    int m,i;
    printf("Enter the Number of Dependencies:-\n");
    scanf("%d",&m);
    struct node *a[n],*last;
    for(i=0;i<n;i++)
      a[i]=NULL;
    printf("Enter the Dependencies in form of U-->>V:-\n");
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=v;
        p->next=NULL;
        if(a[u]==NULL)
        {
            a[u]=p;
            last=p;
        }
        else
        {
            last->next=p;
            last=p;
        }
    }
    printf("DIRECTED GRAPH:-\n");
    for(i=0;i<n;i++)
    {
        printf("%d-->>",i);
        struct node *ptr=a[i];
        if(ptr==NULL)
            printf("NULL");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    int source[n],j;
    for(i=0;i<n;i++)
        source[i]=0;
    for(i=0;i<n;i++)
    {
       int flag=1;
       for(j=0;j<n;j++)
       {
           if(j!=i)
           {
               struct node *ptr=(struct node *)malloc(sizeof(struct node));
               ptr=a[j];
               while(ptr!=NULL)
               {
                   if(ptr->data==i)
                   {
                       flag=0;
                       break;
                   }
                   ptr=ptr->next;
               }
           }
           if(flag==0)
            break;
       }
       if(flag==1)
         source[i]=1;
    }
    printf("SOURCE VERTEX:-\n");
    for(i=0;i<n;i++)
    {
        if(source[i]==1)
            printf("%d ",i);
    }
    return 0;
}

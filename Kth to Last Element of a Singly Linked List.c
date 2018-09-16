#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;
void createlinkedlist()
{
    printf("Enter the number of nodes:-\n");
    int n,i;
    scanf("%d",&n);
    printf("Enter the Data:-\n");
    for(i=0;i<n;i++)
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(start==NULL)
            start=p;
        else
        {
            struct node *ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=p;
        }
    }
}
void find_kth_fromlast(int k)
{
    struct node *curr=start,*prev=start;
    if(curr==NULL)
        printf("LIST IS EMPTY\n");
    else
    {
        while(curr!=NULL)
        {
            if(k<=0)
                prev=prev->next;
            k--;
            curr=curr->next;
        }
        if(prev==start && k>0)
            printf("Value of K is more than Size\n");
        else
            printf("%Kth Element From Last=%d",prev->data);
    }
}
void printlinkedlist()
{
    printf("\nLINKED LIST:-\n");
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    createlinkedlist();
    printlinkedlist();
    int k;
    printf("\nEnter the Value of K:-\n");
    scanf("%d",&k);
    find_kth_fromlast(k);
    return 0;
}


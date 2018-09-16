#include<stdio.h>
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
void removeduplicate()
{
    struct node *curr=start,*prev=NULL,*del;
    if(curr==NULL)
        return;
    else
    {
        while(curr->next!=NULL)
        {
            del=curr->next;
            prev=curr;
            while(del->data!=curr->data && del->next!=NULL)
            {
                prev=del;
                del=del->next;
            }
            if(del->data==curr->data && del->next!=NULL)
            {
                prev->next=del->next;
                free(del);
            }
            else if(del->data==curr->data && del->next==NULL)
            {
                prev->next=NULL;
                free(del);
            }
            curr=curr->next;
        }
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
    removeduplicate();
    printlinkedlist();
    return 0;
}

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
void printlinkedlist()
{
    printf("LINKED LIST:-\n");
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void reverseLinkedList()
{
    struct node *ptr=start;
    int top=-1,st[100];
    while(ptr!=NULL)
    {
        st[++top]=ptr->data;
        ptr=ptr->next;
    }
    ptr=start;
    while(top!=-1 && ptr!=NULL)
    {
        ptr->data=st[top--];
        ptr=ptr->next;
    }
}
int main()
{
    createlinkedlist();
    printlinkedlist();
    reverseLinkedList();
    printf("REVERSED ");
    printlinkedlist();
    return 0;
}

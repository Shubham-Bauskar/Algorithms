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
    printf("\nLINKED LIST:-\n");
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void partition(int x)
{
    struct node *loc=start,*left=start,*right=NULL;
    while(loc->data!=x && loc!=NULL)
        loc=loc->next;
    if(loc==NULL)
        return;
    else
    {
        right=loc->next;
        while(1)
        {
            while(right->data >= loc->data && right!=NULL)
                right=right->next;
            if(right==NULL)
                break;
            if(right->data < loc->data)// Right contains smaller element
            {
                int temp=right->data;
                right->data=loc->data;
                loc->data=temp;
                loc=right;
                printlinkedlist();
                printf(" loc=%d right=%d left=%d\n",loc->data,right->data,left->data);
            }
            while(left->data < loc->data && left!=loc)
                left=left->next;
            if(left==loc)
                return;
            if(left->data >= loc->data)
            {
                int temp=left->data;
                left->data=loc->data;
                loc->data=temp;
                loc=left;
                printlinkedlist();
                printf(" loc=%d right=%d left=%d\n",loc->data,right->data,left->data);
            }
            left=start;
            right=loc->next;
            printf("new-loc=%d new-right=%d new-left=%d\n",loc->data,right->data,left->data);
        }
    }
}
int main()
{
    createlinkedlist();
    printlinkedlist();
    int x;
    printf("\nEnter the Value of Pivot\n");
    scanf("%d",&x);
    partition(x);
    printlinkedlist();
    return 0;
}


#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL,*start1=NULL,*ans=NULL,*anstail=NULL;
void createlinkedlist(struct node **q)
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
        if(*q==NULL)
            *q=p;
        else
        {
            struct node *ptr=*q;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=p;
        }
    }
}
void printlinkedlist(struct node **q)
{
    printf("LINKED LIST:-\n");
    struct node *ptr=*q;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void sum()
{
    struct node *p=start,*q=start1;
    int carry=0,val=0;
    while(p!=NULL && q!=NULL)
    {
        val=p->data +q->data+carry;
        carry=val/10;
        val=val%10;
        struct node *t=(struct node*)malloc(sizeof(struct node));
        t->data=val;
        t->next=NULL;
        if(ans==NULL)
        {
            ans=t;
            anstail=t;
        }
        else
        {
            anstail->next=t;
            anstail=t;
        }
        p=p->next;
        q=q->next;
    }
    if(carry!=0 && p==NULL && q==NULL)
    {
       struct node *t=(struct node*)malloc(sizeof(struct node));
       t->data=carry;
       t->next=NULL;
       anstail->next=t;
       anstail=t;
    }
    if(p==NULL)
    {
        while(q!=NULL)
        {
            val=q->data+carry;
            carry=val/10;
            val=val%10;
            struct node *t=(struct node*)malloc(sizeof(struct node));
            t->data=val;
            t->next=NULL;
            if(ans==NULL)
            {
                ans=t;
                anstail=t;
            }
            else
            {
                anstail->next=t;
                anstail=t;
            }
            q=q->next;
        }
    }
    if(q==NULL)
    {
        while(p!=NULL)
        {
            val=p->data+carry;
            carry=val/10;
            val=val%10;
            struct node *t=(struct node*)malloc(sizeof(struct node));
            t->data=val;
            t->next=NULL;
            if(ans==NULL)
            {
                ans=t;
                anstail=t;
            }
            else
            {
                anstail->next=t;
                anstail=t;
            }
            p=p->next;
        }
    }
}
int main()
{
    createlinkedlist(&start);
    //printlinkedlist(&start);
    createlinkedlist(&start1);
    //printlinkedlist(&start1);
    sum();
    printf("SUM OF 2 LINKED LIST:-\n");
    printlinkedlist(&ans);
    return 0;
}


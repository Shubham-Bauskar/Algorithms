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
int palindrome()
{
    struct node *p=start;
    int top=-1;
    int stack[100];
    while(p!=NULL)
    {
        stack[++top]=p->data;
        p=p->next;
    }
    int stacktemp[100],toptemp=-1;
    if(top%2==0)
    {
        int k=top/2;
        while(top!=k)
            stacktemp[++toptemp]=stack[top--];
        top--;
        while(top!=-1 && toptemp!=-1)
        {
            if(stack[top--]!=stacktemp[toptemp--])
                return 0;
        }
        return 1;
    }
    else
    {
        int k=top/2;
        while(top!=k)
            stacktemp[++toptemp]=stack[top--];
        while(top!=-1 && toptemp!=-1)
        {
            if(stack[top--]!=stacktemp[toptemp--])
               return 0;
        }
        return 1;
    }
    return 1;
}
int main()
{
    createlinkedlist();
    printlinkedlist();
    if(palindrome()==1)
        printf("--YES\n");
    else
        printf("--NO");
    return 0;
}
// Reversing a LL using a new LL then each time add the new node at the beginning of the new LL while traversing the old LL
// S(n)=O(n);

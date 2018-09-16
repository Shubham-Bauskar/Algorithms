#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *a[5];
    int top;
    int stk;
};
void push(struct stack *p,int x)
{
    if(p->stk==4 && p->top==9) // ALL STACK IS FULL
    {
       printf("STACK IS FULL\n");
       return;
    }
    if(p->stk==0 && p->top==-1) // FIRST ELEMENT IS PUSHED
    {
        p->a[p->stk]=(int *)malloc(10*sizeof(int));
        p->top=p->top+1;
        p->a[p->stk][p->top]=x;
    }
    else if(p->top==9) // ONE STACK IS FILLED,CREATE NEW STACK
    {
        p->stk=p->stk +1;
        p->a[p->stk]=(int *)malloc(10*sizeof(int));
        p->top=0;
        p->a[p->stk][p->top]=x;
    }
    else
    {
        p->top=p->top+1;
        p->a[p->stk][p->top]=x;
    }
}
int pop(struct stack *p)
{
    int x;
    if(p->stk==0 && p->top==-1) //STACK IS EMPTY
    {
        printf("STACK IS EMPTY ie No. of ELEMENTS LEFT=");
        return 0;
    }
    else if(p->top==0 && p->stk>0) // LAST ELEMENT OF INNER STACK IS POPED
    {
        x=p->a[p->stk][p->top];
        p->top=9;
        p->stk=p->stk-1;
        return x;
    }
    else if(p->top==0 && p->stk==0) //LAST ELEMENT IS POPED
    {
        x=p->a[p->stk][p->top];
        p->top=-1;
        return x;
    }
    else
    {
        x=p->a[p->stk][p->top];
        p->top=p->top-1;
        return x;
    }
}
int main()
{
    int i;
    struct stack s;
    s.top=-1;
    s.stk=0;
    for(i=1;i<=52;i++)
        push(&s,i);
    printf("POPED ELEMENTS:-\n");
    for(i=1;i<=52;i++)
        printf("%d\n",pop(&s));
    return 0;
}

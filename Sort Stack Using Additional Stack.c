#include<stdio.h>
struct stack
{
    int a[100];
    int top;
};
void push(struct stack *s,struct stack *ad,int x)
{
    if(s->top==-1)
        s->a[++s->top]=x;
    else
    {
        while(s->a[s->top]<x && s->top!=-1)
        {
            //Pop that element and store it in additional stack
            ad->a[++ad->top]=s->a[s->top--];
        }
        s->a[++s->top]=x;
        while(ad->top!=-1)
        {
            //Put all poped elements of main stack back into it
            s->a[++s->top]=ad->a[ad->top--];
        }
    }
}
int pop(struct stack *p)
{
    return p->a[p->top--];
}
int main()
{
    struct stack s,ad; //ad=Additional Stack
    s.top=ad.top=-1;
    printf("Push 10 values into the Stack randomly:-\n");
    int i;
    for(i=1;i<=10;i++)
    {
        int x;
        scanf("%d",&x);
        push(&s,&ad,x);
    }
    printf("Poping in Sorted Order:-\n");
    while(s.top!=-1)
        printf("%d\n",pop(&s));
    return 0;
}

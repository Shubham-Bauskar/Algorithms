#include<stdio.h>
struct queue
{// 2 Stacks one for insertion && one for deletion
    int stinsert[10];
    int stdel[10];
    int topi;
    int topd;
};
void add(struct queue *p,int x)
{
    p->topi=p->topi+1;
    p->stinsert[p->topi]=x;
}
int del(struct queue *p)
{
    if(p->topi==-1 && p->topd==-1)//Both are Empty
    {
        printf("Queue is Empty\n");
        return;
    }
    else if(p->topi!=-1 && p->topd==-1)//Stack s1(insert) is not empty and s2(del) is Empty so to delete
    {                                  // shift all elements of s1 to s2 and delete from s2
        while(p->topi!=-1)
        {
            int x=p->stinsert[p->topi--];
            p->stdel[++p->topd]=x;
        }
    }
    return p->stdel[p->topd--]; //if s2 is not empty than delete from s2 only
}
int main()
{
    struct queue q;
    q.topi=q.topd=-1;
    int i;
    for(i=1;i<=7;i++)
        add(&q,i);
    for(i=1;i<=5;i++)
        printf("%d\n",del(&q));
    for(i=11;i<=13;i++)
        add(&q,i);
    printf("%d\n",del(&q));
    printf("%d\n",del(&q));
    printf("%d\n",del(&q));
    return 0;
}

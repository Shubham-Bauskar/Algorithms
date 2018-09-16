#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    struct node *next;
};
void trim(struct node *p)
{
    struct node *p1=p,*p2=NULL,*p3=NULL;
    if(p->next!=NULL)
        p2=p->next;
    if((p->next)->next!=NULL)
        p3=(p->next)->next;
    while(p3->next!=NULL)//p3 is pointing at last node
    {
        if(p1->x==p2->x || p1->y==p2->y)//same node so delete node pointed by p2
        {
            p1->next=p3;
            delete(p2);
            p2=p3;
            p3=p3->next;
        }
        else
        {//No node is to be deleted then move forward
            p1=p1->next;
            p2=p2->next;
            p3=p3->next;
        }
    }
    if(p2->x==p3->x || p2->y==p3->y)//Delete the Last Node
    {
        p2->next=NULL;
        delete(p3);
    }
}
int main()
{
    struct node *head=NULL,*back=NULL;
    int n;
    cout<<"Enter Number of Nodes:-"<<endl;
    cin>>n;
    cout<<"Enter the coordinates of Points:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->x=x;
        p->y=y;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            back=p;
        }
        else
        {
            back->next=p;
            back=p;
        }
    }
    trim(head);
    cout<<"Processed LinkedList:-"<<endl;
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"("<<ptr->x<<","<<ptr->y<<")"<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    return 0;
}

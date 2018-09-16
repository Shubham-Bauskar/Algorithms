#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int path=0;
bool findpath(struct node *p,int key)
{
    if(p==NULL && key!=0)
        return false;
    if(key==0)
        return true;
    key-=p->data;
    bool a=findpath(p->left,key);
    bool b=findpath(p->right,key);
    return a||b;
}
void inorder(struct node *p,int key)
{
    if(p!=NULL)
    {
        if(findpath(p,key)==true)
        {
            path++;
            cout<<"--"<<p->data<<endl;
        }
        inorder(p->left,key);
        inorder(p->right,key);
    }
}
void createbst(int x)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=p->right=NULL;
    if(root==NULL)
        root=p;
    else
    {
        struct node *ptr=root,*prev;
        while(ptr!=NULL)
        {
            prev=ptr;
            if(ptr->data >=x)
                ptr=ptr->left;
            else if(ptr->data <x)
                ptr=ptr->right;
        }
        if(prev->data < x)
            prev->right=p;
        else
            prev->left=p;
    }
}
int main()
{
    int n;
    printf("Enter Number of Values:-\n");
    cin>>n;
    cout<<"Enter the Values:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        createbst(x);
    }
    int key;
    cout<<"Enter Sum of Path To be Found"<<endl;
    cin>>key;
    cout<<"Starting Node of Path"<<endl;
    inorder(root,key);
    cout<<"No of Paths With Given Sum="<<path;
    return 0;
}


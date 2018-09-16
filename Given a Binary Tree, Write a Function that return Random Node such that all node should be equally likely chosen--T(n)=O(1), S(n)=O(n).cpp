#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int t=0;
void inorder(struct node *p,int a[])
{
    if(p!=NULL)
    {
        if(p->left!=NULL)
            inorder(p->left,a);
        a[t++]=p->data;
        if(p->right!=NULL)
            inorder(p->right,a);
    }
}
int getrandom(int a[],int n)
{
    int x=rand();
    x=x%n;
    return a[x];
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
    cout<<"Enter Number of Nodes:-"<<endl;
    cin>>n;
    cout<<"Enter the Values:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        createbst(x);
    }
    int a[n];
    inorder(root,a);
    cout<<"Inorder Traversal:-"<<endl;
    for(int i=0;i<t;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Random Nodes:-"<<endl;
    for(int i=1;i<=100;i++)
        cout<<getrandom(a,n)<<endl;
    return 0;
}


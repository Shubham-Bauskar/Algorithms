#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
    int bf,height;
}*root=NULL;
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
int findfirstCommonAncestor(struct node *p,int a,int b)
{
    if(p!=NULL)
    {
        if(p->data > a && p->data > b)//Lies in Left SubTree
            return findfirstCommonAncestor(p->left,a,b);
        if(p->data < a && p->data < b)//Lies in Right SubTree
            return findfirstCommonAncestor(p->right,a,b);
        return p->data;
    }
}
int main()
{
    int n;
    printf("Enter the Number of Nodes:-\n");
    scanf("%d",&n);
    int i;
    printf("Enter the Elements in Tree:-\n");
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        createbst(x);
    }
    int a,b;
    cout<<"Enter the Nodes whose Common Ancestor is to be Found:-"<<endl;
    cin>>a>>b;
    cout<<"First Common Ancestor:-"<<endl;
    cout<<findfirstCommonAncestor(root,a,b);
    return 0;
}


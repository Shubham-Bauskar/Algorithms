#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int bst=1;
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
void checkbst(struct node *p,int minimum,int maximum)
{   // min < node <= max // valid node
    printf("Range::(%d,%d) Node::%d\n",minimum,maximum,p->data);
    if(p->data <= minimum || p->data > maximum)//out of range
    {
        bst=0;
        return;
    }
    if(p->left!=NULL)// if node is in range then leftST would be in (min,p->data]
        checkbst(p->left,minimum,p->data);
    if(p->right!=NULL)// RightST is in range (p->data,max)
        checkbst(p->right,p->data,maximum);
}
int main()
{
    int n,i;
    printf("Enter number of Nodes:-\n");
    scanf("%d",&n);
    printf("Enter the Elements:-\n");
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        createbst(x);
    }
    checkbst(root,-214748364,214748264);
    if(bst==1)
        printf("BINARY TREE IS BINARY SEARCH TREE");
    else
        printf("BINARY TREE IS NOT A BINARY SEARCH TREE");
    return 0;
}


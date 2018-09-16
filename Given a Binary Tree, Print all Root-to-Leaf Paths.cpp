#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int arr[100];
int top=-1;
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
void printallpaths(struct node *p)
{
    arr[++top]=p->data;
    if(p->left==NULL && p->right==NULL)// P is a Leaf Node
    {
        for(int i=0;i<=top;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        top--;
        return;
    }
    if(p->left!=NULL)
        printallpaths(p->left);
    if(p->right!=NULL)
        printallpaths(p->right);
    top--;
}
int main()
{
    int n;
    printf("Enter Number of Nodes:-\n");
    cin>>n;
    cout<<"Enter the Values:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        createbst(x);
    }
    cout<<"All Possible Paths:-"<<endl;
    printallpaths(root);
    return 0;
}


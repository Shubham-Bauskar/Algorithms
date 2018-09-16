#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int arr[100];
int top=-1;
//int sum=0;
// Use Sum if S(n)=O(1).
// Use Arr if S(n)=O(logn) but we want to print Path.
int flag=0;
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
void printallpaths(struct node *p,int key)
{
    arr[++top]=p->data;
    //sum+=p->data;
    if(p->left==NULL && p->right==NULL)// P is a Leaf Node
    {
        int s=0;
        for(int i=0;i<=top;i++)
            s+=arr[i];
        if(s==key)
        {
           cout<<"Leaf Node of that Path="<<p->data<<endl;
           cout<<"Path that has Sum Equals to Key"<<endl;
           for(int i=0;i<=top;i++)
              cout<<arr[i]<<" ";
           flag=1;
           cout<<endl;
        }
        top--;
        //sum-=p->data;
        return;
    }
    if(p->left!=NULL)
        printallpaths(p->left,key);
    if(p->right!=NULL)
        printallpaths(p->right,key);
    top--;
    //sum-=p->data;
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
    int key;
    cout<<"Enter the Path Sum to be Search:-"<<endl;
    cin>>key;
    printallpaths(root,key);
    if(flag==0)
        cout<<"No Such Path Exists"<<endl;
    return 0;
}

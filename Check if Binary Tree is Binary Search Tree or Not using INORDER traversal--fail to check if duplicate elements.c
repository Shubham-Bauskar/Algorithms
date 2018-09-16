#include<stdio.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
int prev;
int bst=-1; // 0=>not BST,1=>BST,-1=>1st node to be entered
void inorder(struct node *p)
{
    if(p->left!=NULL)
        inorder(p->left);
    printf("%d ",p->data);
    if(bst==-1) // 1st node is to be entered
    {
        prev=p->data;
        bst=1;
    }
    else if(bst==1) // till now tree is BST
    {
        if(prev<=p->data)
            prev=p->data;
        else
            bst=0;
    }
    if(p->right!=NULL)
        inorder(p->right);
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
void preorder(struct node *p)
{
    printf("%d ",p->data);
    if(p->left!=NULL)
        preorder(p->left);
    if(p->right!=NULL)
        preorder(p->right);
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
    printf("INORDER TRAVERSAL:-");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL:-");
    preorder(root);
    printf("\n");
    if(bst==1)
        printf("BINARY TREE IS BINARY SEARCH TREE");
    else
        printf("BINARY TREE IS NOT A BINARY SEARCH TREE");
    return 0;
}

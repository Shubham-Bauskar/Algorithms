#include<stdio.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
void preorder(struct node *p)
{
    printf("%d ",p->data);
    if(p->left!=NULL)
        preorder(p->left);
    if(p->right!=NULL)
        preorder(p->right);
}
void inorder(struct node *p)
{
    if(p->left!=NULL)
        inorder(p->left);
    printf("%d ",p->data);
    if(p->right!=NULL)
        inorder(p->right);
}
void postorder(struct node *p)
{
    if(p->left!=NULL)
        postorder(p->left);
    if(p->right!=NULL)
        postorder(p->right);
    printf("%d ",p->data);
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
    int i;
    printf("Enter 10 Values:-\n");
    for(i=0;i<10;i++)
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
    printf("POSTORDER TRAVERSAL:-");
    postorder(root);
    return 0;
}

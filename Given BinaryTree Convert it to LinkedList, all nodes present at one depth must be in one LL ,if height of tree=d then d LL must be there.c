#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *next;
}*L[100];
struct node
{
    int data;
    int height;
    struct node *left,*right;
}*root=NULL;
void preorder(struct node *p)
{
    printf("%d(%d) ",p->data,p->height);
    if(p->left!=NULL)
        preorder(p->left);
    if(p->right!=NULL)
        preorder(p->right);
}
void inorder(struct node *p)
{
    if(p->left!=NULL)
        inorder(p->left);
    printf("%d(%d) ",p->data,p->height);
    if(p->right!=NULL)
        inorder(p->right);
}
void postorder(struct node *p)
{
    if(p->left!=NULL)
        postorder(p->left);
    if(p->right!=NULL)
        postorder(p->right);
    printf("%d(%d) ",p->data,p->height);
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
int height(struct node *p)
{
    if(p==NULL)
        return 0;
    int l=height(p->left);
    int r=height(p->right);
    if(r>=l)
        return 1+r;
    return 1+l;
}
void setheight(struct node *child,struct node *parent)
{
    if(child!=NULL)
    {
        child->height=1+parent->height;
        if(child->left!=NULL)// Left grandchild exits
            setheight(child->left,child);
        if(child->right!=NULL)// Left grandchild exits
            setheight(child->right,child);
    }
}
void createList(struct node *ptr)
{
    if(ptr!=NULL)
    {
        int x=ptr->height;
        struct list *p=(struct list *)malloc(sizeof(struct list));
        p->data=ptr->data;
        p->next=NULL;
        if(L[x]==NULL)
            L[x]=p;
        else
        {
            struct list *s=L[x];
            while(s->next!=NULL)
                s=s->next;
            s->next=p;
        }
        createList(ptr->left);
        createList(ptr->right);
    }
}
int main()
{
    int n,i;
    printf("Enter Number of Nodes:-\n");
    scanf("%d",&n);
    printf("Enter the Elements:-\n");
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        createbst(x);
    }
    root->height=0;
    setheight(root->left,root);
    setheight(root->right,root);
    printf("INORDER TRAVERSAL:-");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL:-");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL:-");
    postorder(root);
    int k=height(root);
    for(i=0;i<k;i++)
        L[i]=NULL;
    createList(root);
    printf("\nLINKED LIST CONVERSION ACCORDING TO HEIGHT:-\n");
    for(i=0;i<k;i++)
    {
        printf("%d-->>",i);
        struct list *ptr=L[i];
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    return 0;
}

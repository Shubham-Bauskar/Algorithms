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
void createminbst(int a[],int low,int high)
{
    if(low<=high)// 1 or more than 1 elements are present
    {
        int mid=(low+high)/2;
        // Adding a[mid] to BST
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=a[mid];
        p->left=p->right=NULL;
        if(root==NULL)
            root=p;
        else
        {
            struct node *prev=NULL,*ptr=root;
            while(ptr!=NULL)
            {
                prev=ptr;
                if(ptr->data < a[mid])
                    ptr=ptr->right;
                else
                    ptr=ptr->left;
            }
            if(prev->data < a[mid])
                prev->right=p;
            else
                prev->left=p;
        }
        // Recursive Call to 2 SubArrays
        createminbst(a,low,mid-1);
        createminbst(a,mid+1,high);
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
int main()
{
    int n;
    printf("Enter the No. of Elements:-\n");
    scanf("%d",&n);
    printf("Enter the Elements in the Array:-\n");
    int *a=(int *)malloc(n*sizeof(int)),i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    createminbst(a,0,n-1);
    printf("\nINORDER TRAVERSAL:-");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL:-");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL:-");
    postorder(root);
    printf("\nHEIGHT OF TREE(Root is at level 0)=%d\n",height(root)-1);
    return 0;
}

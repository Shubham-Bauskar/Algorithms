#include<stdio.h>
struct node
{
    int data;
    struct node *left,*right;
    int bf,height;
}*root=NULL;
int balanced=1;
void inorder(struct node *p)
{
    if(p->left!=NULL)
        inorder(p->left);
    printf("%d[%d]",p->data,p->height);
    int l=0,r=0;
    if(p->left!=NULL)
        l=(p->left)->height+1;
    if(p->right!=NULL)
        r=(p->right)->height+1;
    p->bf=l-r;
    printf("{%d} ",p->bf);
    if(p->bf < -1 || p->bf > 1)
        balanced=0;
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
int findheightST(struct node *p)
{
    if(p->left==NULL && p->right==NULL)
    {// If no child/SubTree then height=0
       p->height=0;
       return 0;
    }
    else
    {// If child exists then Height is max of height of left,right + 1
        int x=0,y=0;
        if(p->left!=NULL)
             x=findheightST(p->left);
        if(p->right!=NULL)
             y=findheightST(p->right);
        if(x<=y)
            p->height=y+1;
        else
            p->height=x+1;
        return p->height;
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
    findheightST(root);
    printf("INORDER TRAVERSAL Node[height]{balancefactor}:-\n");
    inorder(root);
    printf("\n");
    if(balanced==0)
        printf("** BINARY TREE IS NOT BALANCED **");
    else
        printf("** BINARY TREE IS BALANCED **");
    return 0;
}

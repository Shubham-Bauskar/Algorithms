#include<stdio.h>
struct node
{
    int data;
    struct node *left,*right,*par;
}*root=NULL;
void inorder(struct node *p)
{
    if(p->left!=NULL)
        inorder(p->left);
    printf("%d ",p->data);
    if(p->right!=NULL)
        inorder(p->right);
}
void createbst(int x)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=p->right=p->par=NULL;
    if(root==NULL)
    {
        root=p;
        p->par=root;
    }
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
        {
            prev->right=p;
            p->par=prev;
        }
        else
        {
             prev->left=p;
             p->par=prev;
        }
    }
}
int inordersuccessor(struct node *p)
{// InOrder Successor of any node is the smallest element in RightST
 // if RightST of the node is not there than check smallest element in RightST of its Parent
    int x=p->data;
    if(p->right==NULL)//NO RightST
    {
       do
       {
		   x=p->data;
           p=p->par;
       }while(p->right==NULL || (p->right)->data==x);
    }
    if(p->right!=NULL)
    {
        p=p->right;
        while(p->left!=NULL)
            p=p->left;
    }
    return p->data;
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
    // Change the Argument of inordersuccessor();
    printf("INORDER SUCCESSOR OF %d=%d\n",(((root->left)->right)->right)->data,inordersuccessor(((root->left)->right)->right));
    return 0;
}



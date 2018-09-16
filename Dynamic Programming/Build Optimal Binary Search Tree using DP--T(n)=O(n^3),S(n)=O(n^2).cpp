#include<bits/stdc++.h>
using namespace std;
void build_optimal_bst(int val[],int freq[],int nodes)
{
    int lookup[nodes][nodes],parent[nodes][nodes];
    for(int i=0;i<nodes;i++)//Only one node i.e (i-th element itself)
    {
        lookup[i][i]=freq[i];//Since only one node the value of BST is the value of that node itself
        parent[i][i]=i;//That node itself is the Root of BST (b/c BST contains only one node)
    }
    for(int i=0;i<nodes;i++)
    {
        for(int j=i+1;j<nodes;j++)//Consider all Elements in BST form i-th to j-th
        {
            int min_val=INT_MAX,root=-1;
            int base=0;
            for(int x=i;x<=j;x++)
                base+=freq[x];
            for(int k=i;k<=j;k++)//Make k-th element as root so
            {
                int left_child=0;
                if(i!=k)
                    left_child=lookup[i][k-1];
                int right_child=0;
                if(j!=k)
                    right_child=lookup[k+1][j];
                if(left_child+right_child<min_val)
                {
                    min_val=left_child+right_child;
                    root=k;
                }
            }
            lookup[i][j]=base+min_val;
            parent[i][j]=root;
        }
    }
    cout<<"Total Cost of Optimal BST="<<lookup[0][nodes-1]<<endl;
    cout<<"Root of BST="<<parent[0][nodes-1]<<endl;
}
int main()
{
    int n;
    cout<<"Enter No. of Nodes in BST:-"<<endl;
    cin>>n;
    int val[n],freq[n];
    cout<<"Enter the Values of Each Node:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter the Frequency of Each Node:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>freq[i];
    build_optimal_bst(val,freq,n);
    return 0;
}

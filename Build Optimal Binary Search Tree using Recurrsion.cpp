#include<bits/stdc++.h>
using namespace std;
int cost_optimal_bst(int freq[],int i,int j)
{
    if(j<i)//No Elements in the BST i.e Invalid SubArray
        return 0;
    if(i==j)//Only one Element in the BST & i.e Cost of BST=freq of Search of that node b/c that not itself is the root
        return freq[i];
    int base=0;
    for(int x=i;x<=j;x++)
        base+=freq[x];
    int min=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        int cost=cost_optimal_bst(freq,i,k-1)+cost_optimal_bst(freq,k+1,j);
        if(cost<min)
            min=cost;
    }
    return min+base;
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
    cout<<"Cost of Optimal BST="<<cost_optimal_bst(freq,0,n-1)<<endl;
    return 0;
}


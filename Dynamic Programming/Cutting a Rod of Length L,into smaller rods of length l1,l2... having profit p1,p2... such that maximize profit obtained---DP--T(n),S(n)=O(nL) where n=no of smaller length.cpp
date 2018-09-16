#include<bits/stdc++.h>
using namespace std;
void cut_max_profit(int len[],int profit[],int n,int l)
{
    int lookup[n][l+1];
    for(int i=0;i<n;i++)//if the length of rod is 0 then we cannot cut it so profit is 0
        lookup[i][0]=0;
    for(int j=1;j<=l;j++)//if we can have only one particular length cut so max profit is no of this type of cut we have to make
        lookup[0][j]=(j/len[0])*profit[0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(len[i]>j)//We cannot use this cut b/c it is of larger length than rod so whatever best we have done so far
                lookup[i][j]=lookup[i-1][j];
            else if(len[i]<=j)//we can use this cut
            {
                //Find max of either use this cut + what max profit we had earn on remaining length of rod earlier
                //or don't use this cut i.e whatever best we had done so far
                lookup[i][j]=max(profit[i]+lookup[i][j-len[i]],lookup[i-1][j]);
            }
        }
    }
    cout<<"Max Profit Obtained="<<lookup[n-1][l]<<endl;
    cout<<"Cuts:-"<<endl;
    int i=n-1,j=l;
    vector<int> cut;
    while(i>0 || j>0)
    {
        int top=lookup[i-1][j];
        if(top==lookup[i][j])//i.e we came from top & we haven't use this cut
            i--;
        else//we have use this cut
        {
            cut.push_back(len[i]);
            j-=len[i];
        }
    }
    for(int i=0;i<cut.size();i++)
        cout<<cut[i]<<" ";
    cout<<endl;
}
int main()
{
    cout<<"Enter the Length of the Rod:-"<<endl;
    int l;
    cin>>l;
    cout<<"Enter no of Length in which we want to cut:-"<<endl;
    int n;
    cin>>n;
    int len[n],profit[n];
    cout<<"Enter length:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>len[i];
    cout<<"Enter the Profit:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>profit[i];
    cut_max_profit(len,profit,n,l);
    return 0;
}

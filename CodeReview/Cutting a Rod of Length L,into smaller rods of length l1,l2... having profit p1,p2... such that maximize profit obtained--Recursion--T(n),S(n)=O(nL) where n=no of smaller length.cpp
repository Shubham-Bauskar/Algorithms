#include<bits/stdc++.h>
using namespace std;
int cut_profit(int len[],int profit[],int n,int l,int i)
{
   if(l==0)//we had made a larger cut
    return profit[i];
   if(i>=n || l<0)
    return 0;
   //use this
   int use_this=profit[i]+cut_profit(len,profit,n,l-len[i],i);
   //not use this
   int not_use=cut_profit(len,profit,n,l,i+1);
   return max(use_this,not_use);
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
    cout<<"Max Profit="<<cut_profit(len,profit,n,l,0);
    return 0;
}


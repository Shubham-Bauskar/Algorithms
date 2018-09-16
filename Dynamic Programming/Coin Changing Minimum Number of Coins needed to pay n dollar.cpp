#include<bits/stdc++.h>
using namespace std;
int minimum_no_of_coins(int coin[],int n,int dollar)
{
    int lookup[n][dollar+1];
    for(int i=0;i<n;i++)//If their is 0$ to be paid then choose no coins
        lookup[i][0]=0;
    for(int j=0;j<=dollar;j++)//If we have only one coin then pay using it only
        lookup[0][j]=j/coin[0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=dollar;j++)
        {
            if(coin[i]<=j)//minimum(pay using that coin,don't use that coin)
                lookup[i][j]=min(1+lookup[i][j-coin[i]],lookup[i-1][j]);
            else//If the value of i-th coin is greater than value to be paid then whatever we had done so far
                lookup[i][j]=lookup[i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=dollar;j++)
            cout<<lookup[i][j]<<" ";
        cout<<endl;
    }
    int i=n-1,j=dollar;
    vector<int> ans;
    while(i>0 && j>0)
    {
        int top=lookup[i-1][j];
        int curr=lookup[i][j];
        if(curr==top)//We haven't pick the i-th coin as we come from top b/c it is minimum
            i--;
        else//We have Pick the i-th coins
        {
            ans.push_back(coin[i]);
            j-=coin[i];
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"Coins Used:-"<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return lookup[n-1][dollar];
}
int main()
{
    int n;
    cout<<"No. of Coins:-"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the Value of Coins:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Amount to be Paid:-"<<endl;
    int dollar;
    cin>>dollar;
    cout<<"Minimum No. of Coins Needed to Pay="<<minimum_no_of_coins(a,n,dollar);
    return 0;
}

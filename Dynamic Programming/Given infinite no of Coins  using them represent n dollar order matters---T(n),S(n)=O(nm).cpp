#include<bits/stdc++.h>
using namespace std;
long int count_ways(int n,vector<int> coin)
{
   int lookup[coin.size()+1][n+1];
   for(int j=0;j<=n;j++)//If we have Zero coins then we cannot pay the cost so No. of Ways=0
      lookup[0][j]=0;
   for(int i=0;i<=coin.size();i++)//If the Cost=0 then their will be only one way to pay the cost by selecting no coins
      lookup[i][0]=1;
   for(int i=1;i<=coin.size();i++)//Consider Coins One by One
   {
       for(int j=1;j<=n;j++)//Consider cost from $1 to $n
       {
           if(coin[i-1]<=j)
           {
               lookup[i][j]=lookup[i-1][j]+lookup[i][j-coin[i-1]];
               //Whatever we had done so far without considering this coin and
               //Pay using this coin & whatever the remaining cost that will be paid using coins 0...i
           }
           else if(coin[i-1]>j)//We cannot use this coin b/c total cost is less than value of that coin
                lookup[i][j]=lookup[i-1][j];//So whatever best we have done so far before considering that coin
       }
   }
   for(int i=0;i<=coin.size();i++)
   {
       for(int j=0;j<=n;j++)
          cout<<lookup[i][j]<<" ";
       cout<<endl;
   }
   return lookup[coin.size()][n];
}
int main()
{
    cout<<"Enter the Amount of Dollars:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the No of Different Types of Coins:-"<<endl;
    int m;
    cin>>m;
    cout<<"Enter the Values of Coins:-"<<endl;
    vector<int> coin;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        coin.push_back(x);
    }
    cout<<"No. of Ways="<<count_ways(n,coin);
    return 0;
}

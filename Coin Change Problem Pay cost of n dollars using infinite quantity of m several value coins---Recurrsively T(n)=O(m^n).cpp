#include<bits/stdc++.h>
using namespace std;
long int count_ways(int n,vector<int> coin,int index)
{
   if(n==0)//Valid Path Found so add that path(coins lying in that path)
     return 1;
   if(n<0)//Invalid Path the coins in that path cannot adds upto the cost
     return 0;
   if(index<0 && n>0)//No coins are left but we have to pay the cost so their is no way
     return 0;
   return count_ways(n,coin,index-1)+count_ways(n-coin[index],coin,index);
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
    cout<<"No. of Ways="<<count_ways(n,coin,coin.size()-1);
    return 0;
}


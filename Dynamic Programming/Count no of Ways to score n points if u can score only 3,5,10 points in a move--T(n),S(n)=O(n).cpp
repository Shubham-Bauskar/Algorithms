#include<bits/stdc++.h>
using namespace std;
int no_of_ways(int n)
{
    int lookup[n+1];
    for(int i=0;i<=n;i++)
        lookup[i]=0;
    lookup[0]=1;//If Score is 0 their is only one way pick no coin
    for(int i=3;i<=n;i++)//Pay using coin 3 and then whatever done best to pay n-3
        lookup[i]+=lookup[i-3];
    for(int i=5;i<=n;i++)//Pay using coin 5 and then whatever done best to pay n-5
        lookup[i]+=lookup[i-5];
    for(int i=10;i<=n;i++)//Pay using coin 7 and then whatever done best to pay n-7
        lookup[i]+=lookup[i-10];
    return lookup[n];
}
int main()
{
    cout<<"Enter the Score:-"<<endl;
    int n;
    cin>>n;
    cout<<"No. of Ways="<<no_of_ways(n);
    return 0;
}
//This Problem can also be solved using Coin Change Problem
//Coin Change Problem T(n)=O(nm),S(n)=O(nm)

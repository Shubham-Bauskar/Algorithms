#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    if(a==0)
        return b;
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    cout<<"Enter the 2 Numbers:-"<<endl;
    int n,m;
    cin>>n>>m;
    cout<<"GCD="<<__gcd(n,m)<<endl;
    cout<<"GCD using Euclidean Algorithm="<<gcd(n,m);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0 || b==0)
        return 0;
    if(a==b)
        return a;
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    return gcd(a-b,b);
}
int main()
{
    cout<<"Enter Two Numbers:-"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"GCD="<<gcd(a,b)<<endl;
    cout<<"Inbuilt GCD Function="<<__gcd(a,b)<<endl;
    return 0;
}

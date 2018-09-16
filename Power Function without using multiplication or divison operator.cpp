#include<bits/stdc++.h>
using namespace std;
int mul(int a,int b)
{
    int ans=0;
    for(int i=0;i<b;i++)
        ans+=a;
    return ans;
}
int power(int a,int b)
{
    if(b==0)
        return 1;
    int ans=1;
    for(int i=0;i<b;i++)
        ans=mul(ans,a);
    return ans;
}
int main()
{
    int a,b;
    cout<<"Enter Numbers:-"<<endl;
    cin>>a>>b;
    cout<<"Power(a,b)="<<power(a,b);
    return 0;
}

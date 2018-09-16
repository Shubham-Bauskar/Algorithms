#include<bits/stdc++.h>
using namespace std;
int power(int x,int y)
{
    if(y==0)
        return 1;
    int t=power(x,y/2);
    if(y%2==0)
        return t*t;
    if(y%2!=0)
        return x*t*t;
}
int main()
{
    cout<<"Enter x & y:-"<<endl;
    int x,y;
    cin>>x>>y;
    cout<<"Pow(x,y)="<<power(x,y)<<endl;
    return 0;
}

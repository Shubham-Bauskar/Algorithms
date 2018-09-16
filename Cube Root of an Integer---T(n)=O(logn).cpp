#include<bits/stdc++.h>
using namespace std;
double finderror(double n,double mid)
{
    return abs(n-mid*mid*mid);
}
double cuberoot(int n)
{
    double e=0.0000001;
    double low=0,high=n/2+1;
    while(true)
    {
        double mid=(low+high)/2.0;
        double error=finderror(n,mid);
        if(error<=e)//More Precise Value Found
            return mid;
        if(mid*mid*mid>n)
            high=mid;
        if(mid*mid*mid<n)
            low=mid;
    }
}
int main()
{
    cout<<"Enter the Number:-"<<endl;
    int n;
    cin>>n;
    cout<<"CUBE ROOT:-"<<endl;
    for(int i=0;i<=n;i++)
        cout<<i<<" "<<cuberoot(i)<<endl;
    return 0;
}

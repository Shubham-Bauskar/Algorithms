#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Elements:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the N-2 Elements:-"<<endl;
    int a[n-2];
    for(int i=0;i<n-2;i++)
        cin>>a[i];
    float s=0,t=0;
    for(int i=0;i<n-2;i++)
    {
        s+=a[i];
        t+=a[i]*a[i];
    }
    s=n*(n+1)/2.0-s;
    t=n*(n+1)*(2*n+1)/6.0-t;
    float p=(s*s-t)/2.0;
    cout<<"Missing Number:-"<<endl;
    cout<<0.5*(s+sqrt(s*s-4*p))<<" "<<0.5*(s-sqrt(s*s-4*p))<<endl;
    return 0;
}

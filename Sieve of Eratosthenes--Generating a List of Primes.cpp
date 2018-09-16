#include<iostream>
using namespace std;
bool isprime(int x)
{
    if(x==2)
        return true;
    else
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                return false;
        }
    }
    return true;
}
int main()
{
    cout<<"Enter the Number"<<endl;
    int n;
    cin>>n;
    char p[n+1];
    for(int i=0;i<=n;i++)
        p[i]='1';
    p[0]=p[1]='0';
    for(int i=2;i*i<=n;i++)
    {
        if(isprime(i)==true)
        {
            for(int k=2*i;k<=n;k+=i)
                p[k]='0';
        }
    }
    cout<<"Prime Factors Upto "<<n<<":-"<<endl;
    for(int i=0;i<=n;i++)
    {
        if(p[i]=='1')
            cout<<i<<" ";
    }
    return 0;
}

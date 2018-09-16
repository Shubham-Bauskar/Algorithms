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
    cout<<"Enter the Number :-"<<endl;
    int n;
    cin>>n;
    int i=2;
    cout<<"Prime Factorization :-"<<endl;
    while(n>1)
    {
        if(isprime(i)==true)
        {
            if(n%i==0)
            {
                cout<<i<<" ";
                n=n/i;
            }
            else
                i++;
        }
        else
            i++;
    }
    return 0;
}

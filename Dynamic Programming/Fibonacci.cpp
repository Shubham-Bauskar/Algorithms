#include<bits/stdc++.h>
using namespace std;
int lookup[1000];
int fib(int n)
{
    if(lookup[n]==-1)//Compute the sub problem & update the lookup table
    {
        if(n<=1)
            lookup[n]=1;
        else
            lookup[n]=fib(n-1)+fib(n-2);
    }
    return lookup[n];
}
int main()
{
    int n;
    cout<<"Enter the Number:-"<<endl;
    cin>>n;
    for(int i=0;i<1000;i++)
        lookup[i]=-1;
    cout<<"Fibonacci="<<fib(n)<<endl;
    return 0;
}

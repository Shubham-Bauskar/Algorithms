#include<bits/stdc++.h>
using namespace std;
int lookup[1000];
int Recursive(int n)
{
    if(n<0)//Invalid Path cannot form if we choose nodes in this path
        return 0;
    if(n==0)//Valid Path we can form 'n' by choosing nodes present in this path
        return 1;
    return Recursive(n-1)+Recursive(n-3)+Recursive(n-5);
}
int dp(int n)
{
    if(lookup[n]==-1)//Compute the sub problem & update the lookup table
    {
        if(n<0)
            return 0;
        else if(n==0)
            lookup[0]=1;
        else
            lookup[n]=dp(n-1)+dp(n-3)+dp(n-5);
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
    cout<<"Recursive="<<Recursive(n)<<endl;
    cout<<"DP="<<dp(n)<<endl;
    return 0;
}

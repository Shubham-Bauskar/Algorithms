#include<bits/stdc++.h>
unsigned long int catalan[20];
using namespace std;
unsigned long int catalan_no(int n)
{
    if(catalan[n]==-1)//1st time we are calculating
    {
        if(n==0)
            return 1;
        unsigned long int sum=0;
        for(int i=0;i<n;i++)
            sum+=catalan_no(i)*catalan_no(n-i-1);
        catalan[n]=sum;
    }
    return catalan[n];
}
int main()
{
    int n;
    cout<<"Enter the Value of N:-"<<endl;
    cin>>n;
    for(int i=0;i<=n;i++)
        catalan[i]=-1;
    catalan[0]=1;
    cout<<"N-th Catalan Number="<<catalan_no(n-1)<<endl;
    return 0;
}

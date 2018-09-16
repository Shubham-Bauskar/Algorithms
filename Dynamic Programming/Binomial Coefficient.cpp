#include<bits/stdc++.h>
using namespace std;
float lookup[1000][1000];
float binomial_coefficient(int n,int r)
{
    if(lookup[n][r]==-1)//Solve & update Lookup
    {
        if(r==0)
            lookup[n][r]=1;
        else if(r==1)
            lookup[n][r]=n;
        else
            lookup[n][r]=binomial_coefficient(n-1,r-1)*n/r;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
            cout<<lookup[i][j]<<" ";
        cout<<endl;
    }
    return lookup[n][r];
}
int main()
{
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            lookup[i][j]=-1;
    for(int j=0;j<1000;j++)
    {
        lookup[j][0]=1;
        lookup[j][1]=j;
    }
    cout<<"Enter 'n' & 'r' :-"<<endl;
    int n,r;
    cin>>n>>r;
    cout<<"C(n,r)="<<binomial_coefficient(n,r);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
float binomial_coefficient(int n,int r)
{
   int c[n+1][r+1];
   for(int i=0;i<=n;i++)//i corresponds to 'n'
   {
       for(int j=0;j<=i;j++)//j corresponds to 'r'
       {
           if(j==0 || j==i)//Base Case
             c[i][j]=1;
           else
             c[i][j]=c[i-1][j]+c[i-1][j-1];
       }
   }
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=i;j++)
         cout<<c[i][j]<<" ";
       cout<<endl;
   }
   return c[n][r];
}
int main()
{
    cout<<"Enter 'n' & 'r' :-"<<endl;
    int n,r;
    cin>>n>>r;
    cout<<"C(n,r)="<<binomial_coefficient(n,r);
    return 0;
}


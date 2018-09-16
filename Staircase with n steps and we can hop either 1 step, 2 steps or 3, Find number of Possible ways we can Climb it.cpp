#include<bits/stdc++.h>
using namespace std;
int a[101];
int rpw(int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return rpw(n-1)+rpw(n-2)+rpw(n-3);
    return 0;
}
int ipw(int n)
{
   if(a[n]!=0)
   {
       cout<<"*"<<n<<"-"<<a[n]<<endl;
       return a[n];
   }
   if(n==0)
   {
       a[0]=1;
       return 1;
   }
   if(n<0)
    return 0;
   a[n]=ipw(n-1)+ipw(n-2)+ipw(n-3);
   cout<<n<<"-"<<a[n]<<endl;
   return a[n];
}
int main()
{
    int n=35;
    cout<<"Enter Number of StairCase:-"<<endl;
    //cin>>n;
    for(int i=0;i<=100;i++)
        a[i]=0;
    //cout<<"Possible Ways(Recursive):-"<<endl<<rpw(n-1)<<endl;
    cout<<"Possible Ways(Iterative):-"<<endl<<ipw(n-1)<<endl;
    return 0;
}

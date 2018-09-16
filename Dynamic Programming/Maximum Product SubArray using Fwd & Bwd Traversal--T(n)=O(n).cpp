#include<bits/stdc++.h>
using namespace std;
int max_product_subarray(int a[],int n)
{
    int max_fwd=INT_MIN,max_bwd=INT_MIN;
    int max_here=1;
    for(int i=0;i<n;i++)
    {
        max_here*=a[i];
        if(max_here==0)
        {
            max_here=1;
            continue;
        }
        if(max_here>max_fwd)
            max_fwd=max_here;
    }
    max_here=1;
    for(int i=n-1;i>=0;i--)
    {
        max_here*=a[i];
        if(max_here==0)
        {
            max_here=1;
            continue;
        }
        if(max_here>max_bwd)
            max_bwd=max_here;
    }
    int prod=max(max_fwd,max_bwd);
    //InCase no SubArray is possible so empty SubArray is the Result have product=0
    return max(prod,0);
}
int main()
{
   cout<<"Enter the Number of Elements in the Array:-"<<endl;
   int n;
   cin>>n;
   int a[n];
   cout<<"Enter the Elements in the Array:-"<<endl;
   for(int i=0;i<n;i++)
        cin>>a[i];
   cout<<"Maximum Product="<<max_product_subarray(a,n)<<endl;
   return 0;
}

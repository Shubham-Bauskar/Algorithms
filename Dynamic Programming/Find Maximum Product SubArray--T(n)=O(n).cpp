#include<bits/stdc++.h>
using namespace std;
void max_product_subarray(int a[],int n)
{
    int max_far=1;
    int max_here=1,min_here=1;
    //max_here is the maximum product SubArray obtain before i-th element
    //min_here is the minimum product SubArray obtain before i-th element
    //min_here either contains odd no. of -ve elements or 1
    //max_here contains even no of -ve elements
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            max_here*=a[i];
            min_here=min(min_here*a[i],1);
        }
        else if(a[i]==0)//Break the Array into sub Parts b/c we have encounter a 0
        {
            min_here=1;
            max_here=1;
        }
        else if(a[i]<0)//Swap min_here & max_here
        {
            int temp=max_here;
            max_here=max(min_here*a[i],1);
            min_here=temp*a[i];
        }
        if(max_here>max_far)
            max_far=max_here;
    }
    cout<<"Maximum Product of SubArray="<<max_far<<endl;
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements of the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    max_product_subarray(a,n);
    return 0;
}

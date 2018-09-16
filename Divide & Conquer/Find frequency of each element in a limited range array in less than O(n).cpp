#include<bits/stdc++.h>
using namespace std;
void compute_frequency(int a[],int low,int high,int b[])
{
    if(low<=high)
    {
        if(a[low]==a[high])
        {
            b[a[low]]+=high-low+1;
            return;
        }
        else
        {
            int mid=(low+high)/2;
            compute_frequency(a,mid+1,high,b);
            compute_frequency(a,low,mid,b);
        }
    }
}
int maximum(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int max=maximum(a,n);
    int b[max+1];
    for(int i=0;i<=max;i++)
        b[i]=0;
    compute_frequency(a,0,n-1,b);
    cout<<"Frequency:-"<<endl;
    for(int i=0;i<=max;i++)
    {
       if(b[i]!=0)
           cout<<i<<"-"<<b[i]<<endl;
    }
    return 0;
}


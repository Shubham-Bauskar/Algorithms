#include<bits/stdc++.h>
using namespace std;
int last_position(int a[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key && mid==high)
            return mid;
        if(a[mid]==key && a[mid+1]>key && mid<high)
            return mid;
        else if(a[mid]>=key)
            return last_position(a,low,mid-1,key);
        return last_position(a,mid+1,high,key);
    }
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
    cout<<"Frequency:-"<<endl;
    for(int i=0;i<n;)
    {
        int lpos=last_position(a,0,n-1,a[i]);
        cout<<a[i]<<"-"<<lpos-i+1<<endl;
        i=lpos+1;
    }
    return 0;
}

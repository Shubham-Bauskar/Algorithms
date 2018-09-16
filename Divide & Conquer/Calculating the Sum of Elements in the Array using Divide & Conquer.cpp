#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int low,int high)
{
    if(low==high)//Only one Elements is Left
        return a[low];
    if(high==low+1)//2 Elements are left
        return a[low]+a[high];
    int mid=(low+high)/2;
    return sum(a,low,mid)+sum(a,mid+1,high);
}
int main()
{
    cout<<"Enter the Number of Elements in an Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"SUM="<<sum(a,0,n-1)<<endl;
    return 0;
}

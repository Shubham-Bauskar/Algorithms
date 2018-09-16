#include<bits/stdc++.h>
using namespace std;
int findmin(int a[],int low,int high)
{
    if(low==high)//Only one Element in the SubArray
        return a[low];
    if(low+1==high)//Two Elements in the SubArray
        return a[low]<a[high]?a[low]:a[high];
    //More than Two Elements
    int mid=(low+high)/2;
    if(a[mid]>a[mid-1] && a[mid]<a[mid+1] && a[mid]>a[low] && a[mid]<a[high])//Check for Sorted SubArray && return A[low]
        return a[low];
    if(a[mid]<a[mid-1] && a[mid]<a[mid+1])
        return a[mid];
    else if(a[mid]<a[low])
        return findmin(a,low,mid-1);
    return findmin(a,mid+1,high);
}
int main()
{
    cout<<"Enter the Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Minimum Element :="<<findmin(a,0,n-1);
    return 0;
}

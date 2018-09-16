#include<bits/stdc++.h>
using namespace std;
int findpivot(int a[],int low,int high)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<a[mid+1] && mid<high)
            return mid;
        if(a[mid-1]>a[mid] && mid>low)
            return mid-1;
        if(a[low]>=a[mid])//Search in left SubArray
            return findpivot(a,low,mid-1);
        else
            return findpivot(a,mid+1,high);
    }
}
int binarysearch(int a[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            cout<<"Found at Index="<<mid<<endl;
            return mid;
        }
        if(a[mid]<key)
            low=mid+1;
        if(a[mid]>key)
            high=mid-1;
    }
    return -1;
}
int main()
{
    cout<<"Enter the Number of Elements:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //Pivot is an element whose next element is smaller than it.
    //At Pivot array is rotated.
    int pivot=findpivot(a,0,n-1);
    int x;
    cout<<"Enter the Element to be Search:-"<<endl;
    cin>>x;
    cout<<"PIVOT="<<pivot<<endl;
    if(binarysearch(a,0,pivot-1,x)==-1)
        binarysearch(a,pivot,n-1,x);
    return 0;
}

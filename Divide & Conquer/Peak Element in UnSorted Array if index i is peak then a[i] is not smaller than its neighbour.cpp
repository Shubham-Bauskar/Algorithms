#include<bits/stdc++.h>
using namespace std;
int findpeak(int a[],int low,int high)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=a[mid+1] && a[mid]>=a[mid-1] && mid>low && mid<high)
            return mid;
        if(a[mid-1]>a[mid] && mid>low)//if mid is smaller than its Left Neighbour then Left SubArray Contains Peak
            return findpeak(a,low,mid-1);
        if(a[mid]<a[mid+1] && mid<high)//if mid is smaller than its Right Neighbour then Right SubArray Contains Peak
            return findpeak(a,mid+1,high);
    }
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
    //peak is an element whose next element is smaller than it.
    //At peak array is rotated.
    int peak=findpeak(a,0,n-1);
    cout<<"Peak is at Index="<<peak<<endl;
    return 0;
}


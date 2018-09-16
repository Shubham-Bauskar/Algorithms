#include<bits/stdc++.h>
using namespace std;
int maxelement(int a[],int low,int high)
{
    if(low==high)
        return a[low];
    if(low+1==high)
        return a[low]>=a[high]?a[low]:a[high];
    if(low+2<=high)//Minimum 3 Elements must be present
    {
        int mid=(low+high)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1])//Middle Element is greater than its adjacent elements
            return a[mid];
        if(a[mid]>=a[mid-1] && a[mid]<=a[mid+1])//Middle elements is not greatest b/c its right sub array contains max elements
            return maxelement(a,mid+1,high);
        if(a[mid]<=a[mid-1] && a[mid]>=a[mid+1])//Middle elements is not greatest b/c its Left sub array contains max elements
            return maxelement(a,low,mid-1);
    }
}
int main()
{
    cout<<"Enter the Number of Elements:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter Elements in Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Maximum Element="<<maxelement(a,0,n-1);
    return 0;
}


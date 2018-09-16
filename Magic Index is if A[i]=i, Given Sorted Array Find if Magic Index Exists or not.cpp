#include<bits/stdc++.h>
using namespace std;
int findmagic1(int a[],int low,int high)//Recursive if all Elements are distinct
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==mid)
            return mid;
        if(a[mid]>mid)//check in left sub array b/c (mid+1)th index will at worst case contains a[mid]+1;
            return findmagic1(a,low,mid-1);
        if(a[mid]<mid)//Check in right sub array b/c (mid-1)th index will at worst case contains a[mid]-1;
            return findmagic1(a,mid+1,high);
    }
    return -1;
}
int findmagic2(int a[],int n)//if elements need not be distinct then magic index can be in both sub arrays
{//so at worst case when all elements are same O(N)
    for(int i=0;i<n;)
    {
        if(a[i]==i)
            return i;
        if(a[i]>i && a[i]<n)//if all elements are same and a[i]>i then match will only be found at index a[i] so skip
            i=a[i];         // so skip checking b/w (i+1)th index & (a[i]-1)th index.
        if(a[i]>i && a[i]>=n)//Value at ith index exceeds the array limit so return not found.
            return -1;
        if(a[i]<i)
            i++;
    }
    return -1;
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
    cout<<"Binary Search Type for Distinct Elements="<<findmagic1(a,0,n-1)<<endl;
    cout<<"Enhanced for Loop for need not be Distinct Elements="<<findmagic2(a,n)<<endl;
    return 0;
}

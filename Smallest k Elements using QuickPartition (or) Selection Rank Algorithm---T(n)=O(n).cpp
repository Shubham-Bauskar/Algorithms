#include<bits/stdc++.h>
using namespace std;
int quick_postion(int a[],int low,int high)
{
    int left=low,right=high;
    int loc=low;
    while(1)
    {
        while(a[loc]<=a[right] && right!=loc)
            right--;
        if(loc==right)
            break;
        else
        {
            int temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        while(a[loc]>=a[left] && left!=loc)
            left++;
        if(loc==left)
            break;
        else
        {
            int temp=a[loc];
            a[loc]=a[left];
            a[left]=temp;
            loc=left;
        }
    }
    return loc;
}
void quickpartition(int a[],int low,int high,int k)
{
    if(low<high)
    {
        int pos=quick_postion(a,low,high);
        if(pos==k-1)//Find the Exact K elements on left SubArray
            return;
        else if(pos>k-1)//Left SubArray Contains greater than k elements so recursively apply on left SubArray
            quickpartition(a,low,pos-1,k);
        else if(pos<k-1)//Right SubArray Contains More Elements & left SubArray contains less elements than k
            quickpartition(a,pos+1,high,k);
    }
}
int main()
{
    cout<<"Enter the Elements in the Array:-"<<endl;
    int n=10;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements of the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cout<<"Enter the Value of k:-"<<endl;
    cin>>k;
    quickpartition(a,0,n-1,k);
    cout<<"K-Smallest Elements:-"<<endl;
    for(int i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
/*
Test case
5 7 1 3 9 8 2 4 10 0
*/

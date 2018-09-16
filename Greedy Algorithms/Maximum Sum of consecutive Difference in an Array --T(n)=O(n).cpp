#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int low,int high)
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
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
      int mid=partition(arr,low,high);
      quicksort(arr,low,mid-1);
      quicksort(arr,mid+1,high);
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
    quicksort(a,0,n-1);
    int sum=0;
    for(int i=0;i<n/2;i++)
    {
		sum-=2*a[i];
		sum+=2*a[n-1-i];
	}
    cout<<"Maximum Sum="<<sum<<endl;
    return 0;
}

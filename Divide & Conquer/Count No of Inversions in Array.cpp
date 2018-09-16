#include<bits/stdc++.h>
using namespace std;
int merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,b[high-low+1],k=0,count=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i];
            i++;
        }
        if(a[i]>a[j])//Inversion
        {
            count+=mid-i+1;
            b[k++]=a[j];
            j++;
        }
        if(a[i]==a[j])
        {
            b[k++]=a[i];
            j++;
        }
    }
    if(i>mid) // First Sub Array Finishes.
    {
        while(j<=high)
        {
            b[k++]=a[j];
            j++;
        }
    }
    if(j>high) // Second Sub Array Finishes.
    {
        while(i<=mid)
        {
            b[k++]=a[i];
            i++;
        }
    }
    int x,y;
    for(x=low,y=0;x<=high && y<k;x++,y++) //Copying Back Temporary Array to Main Array
        a[x]=b[y];
    return count;
}
int count_inversion(int a[],int low,int high)
{
  if(low==high)//Base Case When Only one Element is Left => NO Inversion
    return 0;
  if(low<high)
  {
      int mid=(low+high)/2;
      int l=count_inversion(a,low,mid);
      int r=count_inversion(a,mid+1,high);
      int lr=merge(a,low,mid,high);
      return l+r+lr;
  }
}
int main()
{
    cout<<"Enter Number of Elements in Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter Elements in Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"No of Inversions="<<count_inversion(a,0,n-1)<<endl;
    cout<<"Sorted Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

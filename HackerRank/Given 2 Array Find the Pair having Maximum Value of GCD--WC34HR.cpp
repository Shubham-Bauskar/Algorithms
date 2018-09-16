#include<iostream>
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
int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    quicksort(a,0,n-1);
    quicksort(b,0,n-1);
    int sum=0,gcdvar=-1;
    for(int i=0;i<n;i++) // A Largest & B's Each Element
    {
        int k=gcd(a[n-1],b[i]);
        if(k>gcdvar)
        {
            gcdvar=k;
            sum=a[n-1]+b[i];
        }
        if(k==gcdvar && sum<a[n-1]+b[i])
            sum=a[n-1]+b[i];
    }
    for(int i=0;i<n;i++)// B Largest & A's Each Element
    {
        int k=gcd(b[n-1],a[i]);
        if(k>gcdvar)
        {
            gcdvar=k;
            sum=b[n-1]+a[i];
        }
        if(k==gcdvar && sum<b[n-1]+a[i])
            sum=b[n-1]+a[i];
    }
    for(int i=0;i<n;i++)// A 2nd Largest & B's Each Element
    {
        int k=gcd(a[n-2],b[i]);
        if(k>gcdvar)
        {
            gcdvar=k;
            sum=a[n-2]+b[i];
        }
        if(k==gcdvar && sum<a[n-2]+b[i])
            sum=a[n-2]+b[i];
    }
    for(int i=0;i<n;i++)// B 2nd Largest & A's Each Element
    {
        int k=gcd(b[n-2],a[i]);
        if(k>gcdvar)
        {
            gcdvar=k;
            sum=b[n-2]+a[i];
        }
        if(k==gcdvar && sum<b[n-2]+a[i])
            sum=b[n-2]+a[i];
    }
    cout<<sum<<endl;
    return 0;
}

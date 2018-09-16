#include<bits/stdc++.h>
using namespace std;
int max(int a,int b,int c)
{
    int t=a;
    if(t<b)
        t=b;
    if(t<c)
        t=c;
    return t;
}
int maxsumlr(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int sum=0;
    int left_sum=-999999;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}
int maxsum(int a[],int low,int high)
{
    if(low==high)//Only one element is left
        return a[low];
    //Atleast 2 Elements are Left
    int mid=(low+high)/2;
    return max(maxsum(a,low,mid),maxsum(a,mid+1,high),maxsumlr(a,low,mid,high));
}
int main()
{
    int n;
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum=maxsum(a,0,n-1);
    cout<<"Maximum Sum SubArray="<<sum<<endl;
    return 0;
}



#include<bits/stdc++.h>
using namespace std;
int binsearch_pos(int a[],int n,int key)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]<key && a[mid+1]>key && mid<high)
            return mid;
        else if(key<a[mid] && mid==low)//Key is less than Array
            return low-1;
        else if(key>a[mid] && mid==high)//Key is greater than the Array
            return high;
        else if(a[mid]>key)//Search in left SubArray
            high=mid-1;
        else
            low=mid+1;
    }
    return n-1;
}
int main()
{
    cout<<"Enter the Number of Elements in both the Array:-"<<endl;
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    cout<<"Enter the Elements in Array1:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Elements in Array2:-"<<endl;
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    int min=INT_MAX;
    for(int i=0;i<m;i++)//For each element in Array2
    {
       int pos=binsearch_pos(a,n,b[i]);
       int tmin=INT_MAX;
       if(pos==-1)//Element is smaller than the Array1
           tmin=a[0]-b[i];
       else if(pos==n-1)//Element is Larger than the Array1
           tmin=b[i]-a[n-1];
       else//Element Lies in Range of Array1{a[0],a[n-1]}
       {
           if(b[i]-a[pos]<=a[pos+1]-b[i])
                tmin=b[i]-a[pos];
           else
                tmin=a[pos+1]-b[i];
       }
       if(tmin<min)
           min=tmin;
    }
    cout<<"Minimum Difference="<<min<<endl;
    return 0;
}

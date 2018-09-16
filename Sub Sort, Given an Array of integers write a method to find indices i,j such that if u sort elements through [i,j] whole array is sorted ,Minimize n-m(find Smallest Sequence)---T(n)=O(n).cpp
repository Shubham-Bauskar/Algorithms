#include<bits/stdc++.h>
using namespace std;
int min_in_middle_right_portion(int a[],int low,int high,int rs)
{
    int min=a[low];
    for(int i=low+1;i<=high;i++)
    {
        if(a[i]<min)
            min=a[i];
    }
    if(min<a[rs])
        return min;
    return a[rs];
}
int max_in_left_middle_portion(int a[],int low,int high,int le)
{
    int max=a[low];
    for(int i=low+1;i<=high;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    if(max>a[le])
        return max;
    return a[le];
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    int max_a[n+1],min_a[n+1];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int le=0,rs=n-1;
    while(le+1<n && a[le]<=a[le+1])
        le++;
    while(rs-1>=0 && a[rs]>=a[rs-1])
        rs--;
    int min=min_in_middle_right_portion(a,le+1,rs-1,rs);
    while(le>=0 && a[le]>=min)
        le--;
    int max=max_in_left_middle_portion(a,le+1,rs-1,le);
    while(rs<n && a[rs]<=max)
        rs++;
    cout<<"SubArray Needed to be Sort={"<<le+1<<","<<rs-1<<"}"<<endl;
    cout<<"SubArray:-"<<endl;
    for(int i=le+1;i<=rs-1;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


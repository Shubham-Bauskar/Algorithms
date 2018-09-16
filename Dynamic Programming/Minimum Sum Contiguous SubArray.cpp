#include<bits/stdc++.h>
using namespace std;
void minimum_sum_subarray(int a[],int n)
{
    int min_so_far=INT_MAX;
    int min_here=0;
    int start=-1,end=-1,s=0;
    for(int i=0;i<n;i++)
    {
        min_here+=a[i];
        if(min_here>0)
        {
            min_here=0;
            s=i+1;
        }
        if(min_so_far>min_here)
        {
            min_so_far=min_here;
            start=s;
            end=i;
        }
    }
    cout<<"Minimum Sum SubArray="<<min_so_far<<endl;
    cout<<"SubArray:-"<<endl;
    for(int i=start;i<=end;i++)
        cout<<a[i]<<" ";
}
int main()
{
    cout<<"Enter No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    minimum_sum_subarray(a,n);
    return 0;
}

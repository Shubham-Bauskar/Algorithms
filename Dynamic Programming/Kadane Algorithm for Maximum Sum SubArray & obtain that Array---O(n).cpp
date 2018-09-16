#include<bits/stdc++.h>
#include<climits>
using namespace std;
void kadane(int a[],int n)
{
    int max_so_far=INT_MIN,max_ending_here=0,start=0,e=0,s=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here=max_ending_here+a[i];
        if(max_so_far < max_ending_here)
        {//Encounter maximum sum segment ending at i so store it.
            max_so_far=max_ending_here;
            start=s;
            e=i;
        }
        if(max_ending_here<0)
        {
            max_ending_here=0;
            s=i+1;//Begin Search for new sequence from next index
        }
    }
    cout<<"Maximum Sum SubArray="<<max_so_far<<endl;
    cout<<"SubArray:-"<<endl;
    for(int i=start;i<=e;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the No. Elements in the Array:-"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    kadane(a,n);
    return 0;
}

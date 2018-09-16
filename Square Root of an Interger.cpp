#include<bits/stdc++.h>
using namespace std;
int sqrt(int n)
{
    if(n==0 || n==1)
    return n;
    long int low=0,high=n/2+1,ans;
    while(low<=high)
    {
        long int mid=(low+high)/2;
        if(mid*mid==n)//Perfect Square
            return mid;
        if(mid*mid<n)
        {
            low=mid+1;
            ans=mid;
        }
        if(mid*mid>n)
            high=mid-1;
    }
    return ans;
}
int main()
{
    cout<<"Enter the Number:-"<<endl;
    int n;
    cin>>n;
    cout<<"SQRT:-"<<endl;
    for(int i=0;i<=n;i++)
        cout<<i<<" "<<sqrt(i)<<endl;
    return 0;
}

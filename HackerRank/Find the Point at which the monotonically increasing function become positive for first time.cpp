#include<bits/stdc++.h>
using namespace std;
int f(int x)
{
    //Monotonically Increasing Function
    return x*x-10*x-20;
}
int binsearch(int low,int high)
{
    if(low==high)//Only one Point to Check
        return low;
    int mid=(low+high)/2;
    if(f(mid)==0 && mid==low)
        return mid;
    if(f(mid)>=0 && f(mid-1)<0 && mid>low)
        return mid;
    if(f(mid)<0)
        return binsearch(mid+1,high);
    return binsearch(low,mid-1);
}
int main()
{
    int low=0;
    int high=1;
    for(;;)
    {
        int ans=f(high);
        if(ans<0)
        {
            low=high;
            high=high*2;
        }
        if(ans>=0)
            break;
    }
    cout<<binsearch(low,high)<<endl;
    return 0;
}

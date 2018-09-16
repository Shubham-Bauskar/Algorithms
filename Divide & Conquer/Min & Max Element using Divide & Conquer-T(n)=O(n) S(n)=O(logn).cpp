#include<bits/stdc++.h>
using namespace std;
void findminmax(int a[],int low,int high,int *pmin,int *pmax)
{
    if(low==high)//Only 1 Element is left
    {
        *pmin=*pmax=a[low];//That Element is itself minimum & maximum
        return;
    }
    if(high-low==1)//Base Case when only 2 Elements are Left find minimum & maximum element among them
    {
        if(a[low]<a[high])
        {
            *pmin=a[low];
            *pmax=a[high];
        }
        else
        {
            *pmin=a[high];
            *pmax=a[low];
        }
        return;
    }
    else if(low<high)//Divide the Array & gather their solutions
    {
        int mid=(low+high)/2;
        findminmax(a,low,mid,pmin,pmax);//Left Subarray
        int min1=*pmin,max1=*pmax;
        findminmax(a,mid+1,high,pmin,pmax);//Rigth Subarray
        int min2=*pmin,max2=*pmax;
        if(min1<min2)
            *pmin=min1;
        else
            *pmin=min2;
        if(max1<max2)
            *pmax=max2;
        else
            *pmax=max1;
    }
}
int main()
{
    cout<<"Enter the Number of Elements:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int min=-1,max=-1;
    findminmax(a,0,n-1,&min,&max);
    cout<<"MIN="<<min<<" "<<"MAX="<<" "<<max;
    return 0;
}

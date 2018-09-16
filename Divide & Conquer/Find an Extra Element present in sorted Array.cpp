#include<bits/stdc++.h>
using namespace std;
int findextra(int a[],int b[],int low,int high)
{
    if(low==high)//Only 1 element is left
        return a[low];
    if(low<high)//Atleast 2 Elements are present
    {
        int mid=(low+high)/2;
        if(a[mid]!=b[mid])
        {
            if(mid>low && a[mid-1]==b[mid-1])//Upto mid-1 index both arrays are similar
                return a[mid];
            return findextra(a,b,low,mid-1);
        }
        return findextra(a,b,mid+1,high);
    }
}
int main()
{
    cout<<"Enter the Number of Elements in 1st Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in 1st Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Elements in 2nd Array:-"<<endl;
    int b[n-1];
    for(int i=0;i<n-1;i++)
        cin>>b[i];
    cout<<"Extra Element="<<findextra(a,b,0,n-1);
    return 0;
}

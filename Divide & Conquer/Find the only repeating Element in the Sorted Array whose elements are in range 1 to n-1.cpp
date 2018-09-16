#include<bits/stdc++.h>
using namespace std;
int repeat_element(int a[],int low,int high)
{
    if(low<high)//2 Elements are Present Atleast
    {
        int mid=(low+high)/2;
        if(a[mid]==a[mid+1] && mid<high)
            return a[mid];
        if(a[mid]==a[mid-1] && mid>low)
            return a[mid];
        if(a[mid]==mid+1)//Up to Mid all elements are in their right position
            return repeat_element(a,mid+1,high);
        return repeat_element(a,low,mid-1);
    }
}
int main()
{
    cout<<"Enter the number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Repeating Element="<<repeat_element(a,0,n-1);
    return 0;
}

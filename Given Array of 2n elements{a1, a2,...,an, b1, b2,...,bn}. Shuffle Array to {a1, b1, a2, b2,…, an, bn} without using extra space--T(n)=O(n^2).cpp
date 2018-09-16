#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter no. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int pos=1;
    for(int j=n/2;j<n;j++)
    {
        int x=a[j];
        for(int i=j-1;i>=pos;i--)
            a[i+1]=a[i];
        a[pos]=x;
        pos+=2;
    }
    cout<<"Shuffle Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

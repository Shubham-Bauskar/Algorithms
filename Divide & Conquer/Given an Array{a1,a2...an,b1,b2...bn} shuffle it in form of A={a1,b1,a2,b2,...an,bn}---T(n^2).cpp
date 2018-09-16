#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int pos=1;
    for(int i=n/2;i<n-1;i++)
    {
        int temp=a[i];
        for(int x=i;x>pos;x--)
            a[x]=a[x-1];
        a[pos]=temp;
        pos+=2;
    }
    cout<<"ReShuffle Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

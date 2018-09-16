#include<bits/stdc++.h>
using namespace std;
void random(int a[],int n)
{
    for(int i=n-1;i>=1;i--)
    {
        int pos=floor(n*rand());
        if(pos>i)
            pos=pos%i;
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
    }
}
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"RANDOM ORDER:-"<<endl;
    for(int x=1;x<=100;x++)
    {
        random(a,n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}

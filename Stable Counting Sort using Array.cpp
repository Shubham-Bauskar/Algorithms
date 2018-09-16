#include<bits/stdc++.h>
using namespace std;
void stable_countingsort(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(max<a[i])
            max=a[i];
    }
    int b[max+1],c[n];
    for(int i=0;i<=max;i++)
        b[i]=0;
    for(int i=0;i<n;i++)
        b[a[i]]++;
    //Cumulative Position
    for(int i=1;i<=max;i++)
        b[i]=b[i]+b[i-1];
    for(int i=0;i<=max;i++)
        b[i]--;
    for(int i=n-1;i>=0;i--)
    {
        if(b[a[i]]>=0)
        {
            c[b[a[i]]]=a[i];
            b[a[i]]--;
        }
    }
    for(int i=0;i<n;i++)
        a[i]=c[i];
}
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    stable_countingsort(a,n);
    cout<<"SORTED ARRAY:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

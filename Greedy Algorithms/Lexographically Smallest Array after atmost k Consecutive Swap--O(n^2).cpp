#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Number of Swaps:-"<<endl;
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        int min=a[i],no_swap=0,pos=i;
        for(int j=1;j<n;j++)
        {
            if(a[j]<min && j-i<=k)//Smaller Element Found & we can Bring it to the i-th  Position
            {
                min=a[j];
                no_swap=j-i;
                pos=j;
            }
        }
        k-=no_swap;
        for(int x=pos-1;x>=i;x--)
            a[x+1]=a[x];
        a[i]=min;
        if(k<=0)
            break;
    }
    cout<<"Lexographically Smallest Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

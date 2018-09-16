#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int b[],int n,int m)
{
    int sp=n+m-1;
    int ap=n-1;
    int bp=m-1;
    while(bp>=0)
    {
        if(ap>=0 && a[ap]>b[bp])//A's Element is greater
        {
            a[sp]=a[ap];
            ap--;
            sp--;
        }
        else//B's Element is greater
        {
            a[sp]=b[bp];
            bp--;
            sp--;
        }
    }
    //Once B is Exhausted no need to check for remaining elements of A's as they are already in their correct position
}
int main()
{
    cout<<"Enter the Size of A:-"<<endl;
    int as;
    cin>>as;
    cout<<"Enter the Number of Elements in A:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in A:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Number of Elements in B:-"<<endl;
    int m;
    cin>>m;
    int b[m];
    cout<<"Enter the Elements in B:-"<<endl;
    for(int i=0;i<m;i++)
        cin>>b[i];
    cout<<"MERGED ARRAY:-"<<endl;
    merge(a,b,n,m);
    for(int i=0;i<n+m;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void shuffle(int a[],int low,int high)
{
    if(high-low==1)//2 Elements are left in the SubArray
        return;
    int mid=(low+high)/2;
    int pos=(low+mid)/2;
    int sp=mid+1;
    for(int i=pos+1;i<=mid;i++,sp++)
    {
        int temp=a[i];
        a[i]=a[sp];
        a[sp]=temp;
    }
    shuffle(a,low,mid);
    shuffle(a,mid+1,high);
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
    shuffle(a,0,n-1);
    cout<<"ReShuffle Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


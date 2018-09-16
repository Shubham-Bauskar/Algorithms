#include<bits/stdc++.h>
using namespace std;
int maximum(int a[],int i,int j,int k)
{
    if(a[i]>=a[j] && a[i]>=a[k])
        return i;
    if(a[j]>=a[k] && a[j]>=a[i])
        return j;
    return k;
}
void peaks_valleys(int a[],int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i+2<n)
        {
            int bigpos=maximum(a,i,i+1,i+2);
            if(bigpos!=i+1)//Middle element is itself not the maximum then place largest element at middle
            {
                int temp=a[bigpos];
                a[bigpos]=a[i+1];
                a[i+1]=temp;
            }
        }
        if(i+1<n)//Last Block
        {
            if(a[i]>a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements of the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    peaks_valleys(a,n);
    cout<<"Peaks & Valleys Pattern:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

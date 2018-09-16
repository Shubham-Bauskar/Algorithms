#include<bits/stdc++.h>
using namespace std;
void maxheapify(int a[],int i,int limit)
{
    int leftson=2*i,rightson=2*i+1;
    int pos=i;
    if(leftson<limit && a[leftson]>a[pos])
        pos=leftson;
    if(rightson<limit && a[rightson]>a[pos])
        pos=rightson;
    if(pos!=i)
    {
        int temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
        maxheapify(a,pos,limit);
    }
}
void buildmaxheap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        maxheapify(a,i,n);
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
    int k;
    cout<<"Enter the Value of k:-"<<endl;
    cin>>k;
    int h[k+1];
    for(int i=0;i<k;i++)
        h[i+1]=a[i];
    buildmaxheap(h,k+1);
    for(int i=1;i<=k;i++)
        cout<<h[i]<<" ";
    for(int i=k;i<n;i++)
    {
        if(a[i]<h[1])//Root posses higher value so make a[i] as the new root b/c we want smallest elements
        {
            h[1]=a[i];
            maxheapify(h,1,k+1);
        }
    }
    cout<<"K-Smallest Elements:-"<<endl;
    for(int i=1;i<=k;i++)
        cout<<h[i]<<" ";
    cout<<endl;
    return 0;
}


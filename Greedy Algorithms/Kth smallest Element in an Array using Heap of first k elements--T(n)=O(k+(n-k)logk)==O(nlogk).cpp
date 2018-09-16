#include<bits/stdc++.h>
using namespace std;
void maxheapify(int a[],int i,int limit)
{
    int loc=i,leftson=2*i,rightson=2*i+1;
    if(leftson<=limit && a[leftson]>a[loc])
        loc=leftson;
    if(rightson<=limit && a[rightson]>a[loc])
        loc=rightson;
    if(loc!=i)
    {
        int temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
        maxheapify(a,loc,limit);
    }
}
void build_max_heap(int a[],int limit)
{
    for(int i=limit/2;i>=1;i--)
        maxheapify(a,i,limit);
}
int main()
{//For kth smallest element
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n+1];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<"Enter the Value of K:-"<<endl;
    int k;
    cin>>k;
    //Build max heap of 1st k elements
    build_max_heap(a,k);
    cout<<"Heap:-"<<endl;
    for(int i=1;i<=k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Algorithm:-"<<endl;
    //For remaining element do
    for(int i=k+1;i<=n;i++)
    {
        if(a[i]<a[1])// if a[i] is smaller than root then make a[i] root & maxheapify
        {
            a[1]=a[i];
            maxheapify(a,1,k);
        }
    }
    cout<<"Kth smallest Element is="<<a[1]<<endl;
    return 0;
}

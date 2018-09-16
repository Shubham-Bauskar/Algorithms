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
void delete_max_heap(int a[],int limit)
{
    int temp=a[limit];
    a[limit]=a[1];
    a[1]=temp;
    maxheapify(a,1,limit-1);
}
int main()
{
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
    build_max_heap(a,n+1);
    cout<<"Heap:-"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Deletion:-"<<endl;
    for(int i=0;i<k-1;i++)//Deletion for K-1 times
    {
        delete_max_heap(a,n-i);
        for(int j=1;j<=n-i-1;j++)
            cout<<a[j]<<" ";
        cout<<endl;
    }
    cout<<"Kth Largest Element is="<<a[1]<<endl;
    return 0;
}

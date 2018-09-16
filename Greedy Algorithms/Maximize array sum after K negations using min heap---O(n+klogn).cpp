#include<bits/stdc++.h>
using namespace std;
void minheapify(int a[],int i,int limit)
{
    int leftson=2*i,rightson=2*i+1,pos=i;
    if(limit>=leftson && a[leftson]<a[pos])
        pos=leftson;
    if(limit>=rightson && a[rightson]<a[pos])
        pos=rightson;
    if(pos!=i)
    {
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
        minheapify(a,pos,limit);
    }
}
void build_min_heap(int a[],int limit)
{
    for(int i=limit/2;i>=1;i--)
        minheapify(a,i,limit);
}
int main()
{
    cout<<"Enter the Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n+1];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build_min_heap(a,n+1);
    cout<<"Min Heap:-"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Enter Number of Negations:-"<<endl;
    int k;
    cin>>k;
    int max_sum=0;
    while(k--)//For Each Pass
    {
        //Negate the Root of min heap(minimum element) & then min heapify the root
        a[1]=-a[1];
        minheapify(a,1,n+1);
    }
    for(int i=1;i<=n;i++)
        max_sum+=a[i];
    cout<<"Max Sum After k Negations="<<max_sum<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void maxheapify(int a[],int i,int limit)
{
    int pos=i;
    int leftson=2*i,rightson=2*i+1;
    if(leftson<=limit && a[pos]<a[leftson])
        pos=leftson;
    if(rightson<=limit && a[pos]<a[rightson])
        pos=rightson;
    if(pos!=i)
    {
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
        maxheapify(a,pos,limit);
    }
}
void minheapify(int a[],int i,int limit)
{
    int pos=i;
    int leftson=2*i,rightson=2*i+1;
    if(leftson<=limit && a[pos]>a[leftson])
        pos=leftson;
    if(rightson<=limit && a[pos]>a[rightson])
        pos=rightson;
    if(pos!=i)
    {
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
        minheapify(a,pos,limit);
    }
}
void build_max_heap(int b[],int limit)
{
    for(int i=limit/2;i>=1;i--)
        maxheapify(b,i,limit);
}
void build_min_heap(int b[],int limit)
{
    for(int i=limit/2;i>=1;i--)
        minheapify(b,i,limit);
}
void delete_min_heap(int a[],int limit)
{
    a[1]=a[limit];
    minheapify(a,1,limit-1);
}
void delete_max_heap(int a[],int limit)
{
    a[1]=a[limit];
    maxheapify(a,1,limit-1);
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    int max_a[n+1],min_a[n+1];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        max_a[i+1]=a[i];
        min_a[i+1]=a[i];
    }
    int i=0,j=n-1;
    build_max_heap(max_a,n);
    build_min_heap(min_a,n);
    cout<<"Max Heap:-"<<endl;
    for(int i=1;i<=n;i++)
        cout<<max_a[i]<<" ";
    cout<<endl<<"Min Heap:-"<<endl;
    for(int i=1;i<=n;i++)
        cout<<min_a[i]<<" ";
    cout<<endl;
    int maxpos=n,minpos=n;
    while(i<=j)
    {
        //Compute Maximum & Minimum Element using min-heap & max-heap
        if(max_a[1]==a[j])
        {
            j--;
            delete_max_heap(max_a,maxpos);
            maxpos--;
        }
        if(min_a[1]==a[i])
        {
            i++;
            delete_min_heap(min_a,minpos);
            minpos--;
        }
        if(max_a[1]!=a[j] && min_a[1]!=a[i])
            break;
    }
    cout<<"SubArray Needed to Sort[i,j]="<<i<<" "<<j<<endl;
    return 0;
}

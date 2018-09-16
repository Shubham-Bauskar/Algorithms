#include<bits/stdc++.h>
using namespace std;
void minheapify(int a[],int i,int limit)
{
    int loc=i,leftson=2*i,rightson=2*i+1;
    if(leftson<=limit)//LeftSon Exists
    {
        if(a[leftson]<a[loc])//LeftSon is smaller than Parent
            loc=leftson;
    }
    if(rightson<=limit)//Right son exists
    {
        if(a[rightson]<a[loc])//Right son is smallest among Parent,left son,right son
            loc=rightson;
    }
    int temp=a[loc];
    a[loc]=a[i];
    a[i]=temp;
    if(loc!=i)//Swapping is Done parent-->child
        minheapify(a,loc,limit);
}
void build_min_heap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        minheapify(a,i,n);
}
int deletion_min_heap(int a[],int limit)
{
    //Swap root with nth element & min heapify root till limit n-1;
    int x=a[1];
    a[1]=a[limit];
    a[limit]=x;
    minheapify(a,1,limit-1);
    return x;
}
void insertion_min_heap(int a[],int val,int limit)
{
    //Place element at last index
    //Swap root with last element & min heapify root
    a[limit+1]=a[1];
    a[1]=val;
    minheapify(a,1,limit+1);
}
int main()
{
    cout<<"Enter the Number of Ropes:-"<<endl;
    int n;
    cin>>n;
    int a[n+1];
    cout<<"Enter the Elements:-"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build_min_heap(a,n+1);
    int cost=0;
    for(int i=0;i<n-1;i++)//Perform n-1 steps finally top of min heap is the total cost
    {
        int x=deletion_min_heap(a,n-i);
        int y=deletion_min_heap(a,n-1-i);
        cost+=x+y;
        insertion_min_heap(a,x+y,n-2-i);
    }
    cout<<"Cost to Connect N Ropes is="<<cost<<endl;
}

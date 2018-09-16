#include<bits/stdc++.h>
using namespace std;
void maxheapify(int a[],int i,int high)
{
    int left=2*i;
    int right=2*i+1;
    int swapi=i;
    if(left<=high)//Left Child Exists
    {
        if(a[left]>a[i])
            swapi=left;
    }
    if(right<=high)//Right Child Exits
    {
        if(a[right]>a[left] && a[right]>a[i])
            swapi=right;
    }
    int temp=a[i];
    a[i]=a[swapi];
    a[swapi]=temp;
    if(swapi!=i)
        maxheapify(a,swapi,high);
}
void buildmaxheap(int a[],int high)
{
    for(int i=high/2;i>=1;i--)
        maxheapify(a,i,high);
}
void heapsort(int a[],int high)
{
    buildmaxheap(a,high);
    cout<<"Max Heap:-"<<endl;
    for(int i=1;i<=high;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=high;i++)
    {
        int temp=a[1];
        a[1]=a[high-i+1];
        a[high-i+1]=temp;
        maxheapify(a,1,high-i);
    }
    cout<<"Heap Sort:-"<<endl;
    for(int i=1;i<=high;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    cout<<"Enter the Number of Elements in Array:-"<<endl;
    int n;
    cin>>n;
    int a[n+1];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    heapsort(a,n);
    return 0;
}

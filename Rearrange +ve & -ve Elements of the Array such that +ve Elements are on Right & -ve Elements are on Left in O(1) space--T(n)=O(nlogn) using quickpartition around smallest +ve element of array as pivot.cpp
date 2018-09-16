#include<bits/stdc++.h>
using namespace std;
void rearrange_pos_neg(int a[],int low,int high)
{
    int min_pos=999999999,min_posi=-1;
    for(int i=0;i<=high;i++)
    {
        if(a[i]>=0 && a[i]<min_pos)
        {
            min_pos=a[i];
            min_posi=i;
        }
    }
    if(min_posi==-1)//All Elements are negative
        return;
    int temp=a[0];
    a[0]=a[min_posi];
    a[min_posi]=temp;
    int loc=0,left=low,right=high;
    while(true)
    {
        while(a[right]>=a[loc] && loc!=right)
            right--;
        if(loc==right)
            break;
        if(a[loc]>a[right])
        {
            int temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        while(a[left]<a[loc] && loc!=left)
            left++;
        if(loc==left)
            break;
        if(a[loc]<a[left])
        {
            int temp=a[loc];
            a[loc]=a[left];
            a[left]=temp;
            loc=left;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the Number of Elements in the Array"<<endl;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    rearrange_pos_neg(a,0,n-1);
    cout<<"Rearranged Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

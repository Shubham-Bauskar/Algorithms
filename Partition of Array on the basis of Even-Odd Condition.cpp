#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the Number of Elements:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Values:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int flag=0;
    for(int i=0,j=n-1;i<=n/2 && j>=n/2;)
    {
        if(a[i]%2==0)
        {
            i++;
            continue;
        }
        if(a[j]%2!=0)
        {
            j--;
            continue;
        }
        if(a[i]%2!=0 && flag==0)
            flag=1;
        if(a[i]%2!=0 && flag==1)
        {
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
            j--;
            flag=0;
        }
        if(a[j]%2==0 && flag==0)
            flag=1;
        if(a[j]%2==0 && flag==1)
        {
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
            j--;
            flag=0;
        }
    }
    cout<<"After Partition:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
partition(first_iterator,last_iterator,condition_function);
C++ in built Function for partition
#include<algorithm>
bool fun(int x)
{
    return x%2==0;
}
int main()
{
    int a[]={2,1,15,6,8,7};
    vector<int> v(a,a+6);
    partition(v.begin(),v.end(),fun);
    vector<int>::iterator p;
    for(p=v.begin();p!=v.end();p++)
        cout<<*p<<" ";
    return 0;
}
stable_partition(v.begin(),v.end(),fun);
*/

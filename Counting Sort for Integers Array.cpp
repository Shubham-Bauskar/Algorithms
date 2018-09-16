#include<bits/stdc++.h>
using namespace std;
void countingsort(int a[],int n)
{
    int max=a[0],min=a[0];
    for(int i=0;i<n;i++)
    {
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    int temp[max-min+1];
    for(int i=0;i<=max-min;i++)
        temp[i]=0;
    for(int i=0;i<n;i++)
        temp[a[i]-min]++;
    int sp=0;
    for(int i=0;i<=max-min;i++)
    {
        while(temp[i]--)
            a[sp++]=i+min;
    }
    cout<<"Counting Sort:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
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
    countingsort(a,n);
    return 0;
}

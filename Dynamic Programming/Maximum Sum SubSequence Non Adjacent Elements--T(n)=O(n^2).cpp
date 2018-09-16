#include<bits/stdc++.h>
using namespace std;
int max_sub_seq_non_adjacent(int a[],int n)
{
    int sum[n];
    for(int i=0;i<n;i++)
        sum[i]=a[i];
    int pos[n];
    for(int i=0;i<n;i++)
        pos[i]=i;
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<=i-2;j++)
        {
            if(sum[j]+a[i]>sum[i])
            {
                sum[i]=sum[j]+a[i];
                pos[i]=j;
            }
        }
    }
    int max=sum[0];
    for(int i=1;i<n;i++)
    {
        if(max<sum[i])
            max=sum[i];
    }
    return max;
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Maximum Sum SubSequence Non Adjacent="<<max_sub_seq_non_adjacent(a,n);
    return 0;
}

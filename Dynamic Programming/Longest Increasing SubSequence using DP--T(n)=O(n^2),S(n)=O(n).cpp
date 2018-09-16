#include<bits/stdc++.h>
using namespace std;
int longest_increasing_subsequence(int a[],int n)
{
    int b[n];
    for(int i=0;i<n;i++)//At least the length of longest increasing subsequence is 1 the element itself
        b[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                int x=1+b[j];
                if(x>b[i])
                    b[i]=x;
            }
        }
    }
    int max=b[0];
    for(int i=1;i<n;i++)
    {
        if(max<b[i])
            max=b[i];
    }
    return max;//Pick the maximum value among all possible LIS values
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements of the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Longest Increasing SubSequence="<<longest_increasing_subsequence(a,n);
    return 0;
}

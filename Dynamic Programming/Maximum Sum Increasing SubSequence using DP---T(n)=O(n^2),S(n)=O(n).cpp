#include<bits/stdc++.h>
using namespace std;
void maximum_sum_increasing_subseq(int a[],int n)
{
    int max_val[n],actual_seq[n];
    for(int i=0;i<n;i++)//At any ith position the maximum subsequence is at least that element itself
    {
        max_val[i]=a[i];
        actual_seq[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])//We can include the ith element in the Subsequence obtained at position jth
            {
                int t=max_val[j]+a[i];
                if(t>max_val[i])//Since adding this generates more value subsequence
                {
                    max_val[i]=t;
                    actual_seq[i]=j;//To store from where we get this sequence
                }
            }
        }
    }
    int max=max_val[0],maxpos=0;
    for(int i=1;i<n;i++)
    {
        if(max<max_val[i])
        {
            max=max_val[i];
            maxpos=i;
        }
    }
    cout<<"Maximum Sum Increasing Subsequence="<<max<<endl;
}
int main()
{
    cout<<"Enter the Size of the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    maximum_sum_increasing_subseq(a,n);
    return 0;
}

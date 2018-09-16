#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        long long int sum[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0)
                sum[i]=a[i];
            else
                sum[i]=sum[i-1]+a[i];
        }
        long long int mins=sum[0]+sum[n-1];
        int mini=0;
        for(int i=1;i<n;i++)
        {
            long long int temp=sum[i]+sum[n-1]-sum[i-1];
            if(temp<mins)
            {
                mins=temp;
                mini=i;
            }
        }
        cout<<mini+1<<endl;
    }
    return 0;
}

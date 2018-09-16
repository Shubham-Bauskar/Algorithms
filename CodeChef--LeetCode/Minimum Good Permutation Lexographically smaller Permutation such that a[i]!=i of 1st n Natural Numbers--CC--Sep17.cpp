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
        for(int i=0;i<n;i++)
            a[i]=i+1;
        if(n%2==0)
        {
          for(int i=0;i<n-1;i+=2)
          {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
          }
        }
        else
        {
           for(int i=0;i<=n-3;i+=2)
           {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
           }
           int temp=a[n-1];
           a[n-1]=a[n-2];
           a[n-2]=temp;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}

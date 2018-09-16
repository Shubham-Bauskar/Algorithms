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
            cin>>a[i];
        int maxv=a[0];
        for(int i=1;i<n;i++)
        {
            if(maxv<a[i])
                maxv=a[i];
        }
        cout<<maxv<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,flag=1;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(a[n/2]!=7)
            flag=0;
        else
        {
            for(int i=0;i<n/2;i++)
            {
                if(a[i]!=a[n-i-1])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int hard=p/10;
        int simple=p/2;
        int hp=0,sp=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=simple)
                sp++;
            else if(a[i]<=hard)
                hp++;
        }
        if(sp==1 && hp==2)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}

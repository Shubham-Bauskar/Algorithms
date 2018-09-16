#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n,k;
        cin>>n>>k;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int pos=(n+k)/2;
        if(pos<n)
            cout<<v[pos]<<endl;
        else
            cout<<n-1<<endl;
    }
    return 0;
}

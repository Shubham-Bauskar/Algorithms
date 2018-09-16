#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int a,b,flag=0;
        cin>>a>>b;
        vector<int> ans;
        while(a!=0 && b!=0)
        {
            int x=a%10+b%10;
            x=x%10;
            ans.push_back(x);
            a=a/10;
            b=b/10;
        }
        if(b==0)
        {
            while(a!=0)
            {
                int x=a%10;
                ans.push_back(x);
                a=a/10;
            }
        }
        if(a==0)
        {
            while(b!=0)
            {
                int x=b%10;
                ans.push_back(x);
                b=b/10;
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}

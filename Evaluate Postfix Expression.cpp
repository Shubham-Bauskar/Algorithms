#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the PostFix Expression"<<endl;
    string s;
    cin>>s;
    int ans[100],top=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48 && s[i]<=57)
            ans[++top]=s[i]-48;
        else
        {
            int x=ans[top--];
            int y=ans[top--];
            if(s[i]=='+')
                ans[++top]=x+y;
            else if(s[i]=='-')
                ans[++top]=x-y;
            else if(s[i]=='*')
                ans[++top]=x*y;
            else if(s[i]=='/')
                ans[++top]=y/x;
        }
    }
    cout<<"Result"<<"="<<ans[top]<<endl;
    return 0;
}

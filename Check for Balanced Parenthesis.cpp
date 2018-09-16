#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the String containing Parenthesis:-"<<endl;
    string s;
    cin>>ws>>s;
    char stk[s.size()];
    int flag=1,top=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')//Opening Parenthesis add it to stack
           stk[++top]=s[i];
        else
        {
            char x=stk[top--];
            if((x=='(' && s[i]!=')')||(x=='{' && s[i]!='}')||(x=='[' && s[i]!=']'))//If for stack top we don't get its complementary pair then its is invalid
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>ws>>s;
        int fh[26],sh[26];
        for(int i=0;i<26;i++)
            fh[i]=sh[i]=0;
        if(s.size()%2==0)
        {
            for(int i=0;i<s.size()/2;i++)
            {
                fh[s[i]-97]++;
                sh[s[i+s.size()/2]-97]++;
            }
        }
        else
        {
            for(int i=0;i<s.size()/2;i++)
            {
                fh[s[i]-97]++;
                sh[s[i+1+s.size()/2]-97]++;
            }
        }
        int flag=1;
        for(int i=0;i<26;i++)
        {
            if(fh[i]!=sh[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}


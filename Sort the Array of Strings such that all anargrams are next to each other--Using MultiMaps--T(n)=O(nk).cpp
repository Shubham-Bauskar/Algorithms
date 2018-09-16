#include<bits/stdc++.h>
using namespace std;
string sortstr(string s)
{
    int as[26];
    for(int i=0;i<26;i++)
        as[i]=0;
    for(int i=0;i<s.size();i++)
        as[s[i]-97]++;
    int sp=0;
    for(int j=0;j<26;j++)
    {
        if(as[j]!=0)
        {
            int x=as[j];
            while(x--)
                s[sp++]=char(97+j);
        }
    }
    return s;
}
int main()
{
    cout<<"Enter the Number of Strings:-"<<endl;
    int n;
    cin>>n;
    vector<string> v;
    cout<<"Enter the Strings:-"<<endl;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>ws>>s;
        v.push_back(s);
    }
    multimap<string,string> m;
    for(int i=0;i<n;i++)
    {
        string s=v[i];
        string temp=sortstr(s);
        m.insert(pair<string,string>(temp,v[i]));
    }
    cout<<"Sorted Arrays Such that all Anagrams are next to each other:-"<<endl;
    multimap<string,string>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
    return 0;
}


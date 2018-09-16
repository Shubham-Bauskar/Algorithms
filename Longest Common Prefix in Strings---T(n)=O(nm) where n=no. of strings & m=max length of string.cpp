#include<bits/stdc++.h>
using namespace std;
string find_longest_common_prefix(string a,string b)
{
    string temp;
    int x=a.size()<=b.size()?a.size():b.size();
    for(int i=0;i<x;i++)
    {
        if(a[i]==b[i])
            temp.push_back(a[i]);
        else
            return temp;
    }
    return temp;
}
int main()
{
    cout<<"Enter Number of Strings:-"<<endl;
    int n;
    cin>>n;
    vector<string> s;
    cout<<"Enter the String:-"<<endl;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>ws>>temp;
        s.push_back(temp);
    }
    //Method 1 (Pairwise Counting)
    string lcp=s[0];
    for(int i=1;i<n;i++)
        lcp=find_longest_common_prefix(lcp,s[i]);
    cout<<"Longest Common Prefix by Method1:-"<<endl;
    cout<<lcp<<endl;
    //Method 2 (character by Character Counting)
    string ans;
    int min_size=99999999;
    for(int i=0;i<n;i++)
    {
        if(s[i].size()<min_size)
            min_size=s[i].size();
    }
    for(int i=0;i<min_size;i++)
    {
        int flag=1;
        int ch=s[0][i];
        for(int j=1;j<n;j++)
        {
            if(s[j][i]!=ch)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Longest Common Prefix by Method2:-"<<endl;
            cout<<ans;
            break;
        }
        else
            ans.push_back(ch);
    }
    return 0;
}

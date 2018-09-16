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
string longest_common_prefix(vector<string> &s,int low,int high)
{
    if(low==high)//Only one String is Left
        return s[low];
    if(high==low+1)//2 Strings are Left
        return find_longest_common_prefix(s[low],s[high]);
    int mid=(low+high)/2;
    string a=longest_common_prefix(s,low,mid);
    string b=longest_common_prefix(s,mid+1,high);
    return find_longest_common_prefix(a,b);
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
    string ans=longest_common_prefix(s,0,s.size()-1);
    cout<<"Longest Common Prefix:-"<<endl;
    cout<<ans<<endl;
    return 0;
}


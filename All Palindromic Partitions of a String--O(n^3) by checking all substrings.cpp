#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s)
{
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}
int main()
{
    cout<<"Enter the String:-"<<endl;
    string s;
    cin>>ws>>s;
    cout<<"Palindromic Partition of String:-"<<endl;
    vector<string> palindromes;
    for(int len=1;len<=s.size();len++)
    {
       for(int i=0;i<=s.size()-len;i++)//For Each Index
       {
            string temp;
            for(int j=i;j<i+len;j++)
                temp.push_back(s[j]);
            if(ispalindrome(temp)==true)
                palindromes.push_back(temp);
       }
    }
    for(int i=0;i<palindromes.size();i++)
        cout<<palindromes[i]<<endl;
    return 0;
}

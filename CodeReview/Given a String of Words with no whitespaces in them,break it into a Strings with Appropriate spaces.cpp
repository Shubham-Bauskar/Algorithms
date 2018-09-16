#include<bits/stdc++.h>
using namespace std;
bool isvalidword(string a,vector<string> &dictionary)
{
    for(int i=0;i<dictionary.size();i++)
    {
        if(a.compare(dictionary[i])==0)
            return true;
    }
    return false;
}
string break_into_words(string &s,vector<string> &dictionary)
{
    string ans;
    for(int i=0;i<s.size();)
    {
        string temp;
        for(int j=i;j<s.size();j++)
        {
            temp.push_back(s[j]);
            if(isvalidword(temp,dictionary)==true)
            {
                i=j+1;
                ans.append(temp);
                ans.append(" ");
                break;
            }
        }
    }
    return ans;
}
int main()
{
    cout<<"Enter the String of Words(No WhiteSpaces in b/w Words)"<<endl;
    string s;
    cin>>ws>>s;
    cout<<"Enter the No of Words in the Dictionary:-"<<endl;
    int n;
    cin>>n;
    vector<string> dictionary;
    cout<<"Enter the Elements of the Dictionary:-"<<endl;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>ws>>temp;
        dictionary.push_back(temp);
    }
    string ans=break_into_words(s,dictionary);
    cout<<ans<<endl;
    return 0;
}

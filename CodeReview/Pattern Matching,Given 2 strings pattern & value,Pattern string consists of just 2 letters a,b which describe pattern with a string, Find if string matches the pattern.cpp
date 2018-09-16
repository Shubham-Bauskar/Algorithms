#include<bits/stdc++.h>
using namespace std;
void match(string value,string pattern)
{
    if(pattern[0]=='b')//Pattern starts with b so replace a-->b && b-->a
    {
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='a')
                pattern[i]='b';
            else
                pattern[i]='a';
        }
    }
    for(int i=0;i<n;i++)
    {
       string pattern_a;
       for(int j=0;j<=i;j++)
        pattern_a.push_back(pattern[j]);
       for(int j=i+1;j<n;j++)
       {

       }
    }
}
int main()
{
    cout<<"Enter the String & Pattern:-"<<endl;
    string value,pattern;
    cin>>value>>ws>>pattern;
    match(value,pattern);
    return 0;
}

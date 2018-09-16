#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the String to Reverse:-"<<endl;
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();)
    {
       int j=i+1;
       while(s[j]!=32 && j<s.size())
           j++;
       int p=i,q=j-1;
       while(p<=q)
       {
           char ch=s[p];
           s[p]=s[q];
           s[q]=ch;
           p++;q--;
       }
       i=j+1;
    }
    cout<<"Reversed String:-"<<endl;
    cout<<s;
    return 0;
}

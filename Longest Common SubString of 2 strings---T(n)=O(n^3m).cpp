#include<bits/stdc++.h>
using namespace std;
bool issubstring(string b,string temp)
{
   if(b.size()<temp.size())
     return false;
   for(int i=0;i<=b.size()-temp.size();i++)
   {
       if(b[i]==temp[0])
       {
           int flag=1;
           for(int x=i;x<i+temp.size();x++)
           {
               if(b[x]!=temp[x-i])
               {
                   flag=0;
                   break;
               }
           }
           if(flag==1)
             return true;
       }
   }
   return false;
}
int main()
{
    cout<<"Enter 2 Strings:-"<<endl;
    string a,b;
    cin>>ws>>a>>b;
    int max_substring_len=0;
    for(int len=1;len<=a.size();len++)//Generate substrings of all length
    {
        for(int i=0;i<=a.size()-len;i++)
        {
            string temp;
            for(int x=i;x<i+len;x++)
                temp.push_back(a[x]);
            if(issubstring(b,temp)==true)
            {
                if(max_substring_len<len)
                    max_substring_len=len;
            }
        }
    }
    cout<<"Length of Longest Common SubString="<<max_substring_len<<endl;
    return 0;
}

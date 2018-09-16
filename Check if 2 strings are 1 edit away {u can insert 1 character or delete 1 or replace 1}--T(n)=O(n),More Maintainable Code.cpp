#include<bits/stdc++.h>
using namespace std;
bool one_edit_away(string a,string b)
{
   if(abs(a.size()-b.size())>1)//String has to be one edit away
    return false;
   if(b.size()<a.size())//Make sure String 2 is longest
   {
       string temp=a;
       a=b;
       b=temp;
   }
   int i=0,j=0,count=0;
   while(i<a.size() && j<b.size())
   {
       if(a[i]!=b[j])//Mismatch Found
       {
           if(count>0)//Found already this is 2nd mismatch
            return false;
           else if(a.size()==b.size())//case of one-replace
           {
               i++;
               j++;
           }
           else//case of one-insert so increment pointer of longest string
               j++;
           count++;//Indicate mismatch has found
       }
       else
       {
           i++;
           j++;
       }
   }
   return true;
}
int main()
{
    cout<<"Enter 2 Strings:-"<<endl;
    string a,b;
    cin>>a>>b;
    cout<<"1-Edit Away="<<one_edit_away(a,b);
    return 0;
}


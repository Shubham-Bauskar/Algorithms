#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int i=1;i<=t;i++)
  {
    cin>>ws;
    string s;
    getline(cin,s);
    reverse(s.begin(),s.end());
    vector<char> v;
    for(int i=0;i<s.size();i++)
        v.push_back(s[i]);
    vector<char>::iterator lp,sp,l;
    lp=v.begin();
    sp=v.begin();
    while(true)
    {
      while(*sp!=32 && sp!=v.end())
        sp++;
      reverse(lp,sp);
      if(sp!=v.end())
      {
         lp=sp+1;
         sp++;
      }
      else
        break;
    }
    cout<<"Case #"<<i<<": ";
    for(l=v.begin();l!=v.end();l++)
      cout<<*l;
    cout<<endl;
  }
  return 0;
}


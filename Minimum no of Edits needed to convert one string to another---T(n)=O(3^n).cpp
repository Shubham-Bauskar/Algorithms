#include<bits/stdc++.h>
using namespace std;
int min_val(int a,int b,int c)
{
    if(a<=b && a<=c)
        return a;
    if(b<=a && b<=c)
        return b;
    return c;
}
int edits(string a,string b,int n,int m)
{
   if(n==0)//String a becomes empty
    return m;
   if(m==0)//String b becomes empty
    return n;
   if(a[n]==b[m])//both have same characters so don't change + whatever best we can done before considering these characters
    return edits(a,b,n-1,m-1);
   return 1+min_val(edits(a,b,n-1,m-1),edits(a,b,n-1,m),edits(a,b,n,m-1));
   //edits(a,b,n-1,m-1)==replace a[n]<-->b[m]
   //edits(a,b,n,m-1)==delete b[m]
   //edits(a,b,n-1,m)==delete a[n]
}
int main()
{
    cout<<"Enter both the Strings;-"<<endl;
    string a,b;
    cin>>a>>ws>>b;
    cout<<"Minimum No. of Edits="<<edits(a,b,a.size()-1,b.size()-1);
    return 0;
}


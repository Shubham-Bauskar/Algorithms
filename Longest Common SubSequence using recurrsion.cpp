#include<bits/stdc++.h>
using namespace std;
int longest_common_subsequence(string a,int apos,string b,int bpos)
{
    if(apos==a.size() || bpos==b.size())//Either one of the String or Both are Empty so No Common SubSequence.
        return 0;
    else if(a[apos]==b[bpos])
        return 1+longest_common_subsequence(a,apos+1,b,bpos+1);
    else if(a[apos]!=b[apos])
    {
       int temp1=longest_common_subsequence(a,apos,b,bpos+1);
       int temp2=longest_common_subsequence(a,apos+1,b,bpos);
       return temp1<=temp2?temp2:temp1;
    }
}
int main()
{
    cout<<"Enter the Strings:-"<<endl;
    string a,b;
    cin>>a>>b;
    cout<<"Length of Longest Common SubSequence="<<longest_common_subsequence(a,0,b,0);
    return 0;
}

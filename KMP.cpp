#include<bits/stdc++.h>
using namespace std;
void computeLPS(string p,int lps[])
{
    lps[0]=0;
    int i=1,j=0;
    while(i<p.size())
    {
        if(p[i]==p[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else//No option left
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
int kmp(string t,string p)
{
    int lps[p.size()];
    computeLPS(p,lps);
    if(p.size()==0 || t.size()==0)//Size are Zero
        return -1;
    int i=0,j=0;
    int n=t.size(),m=p.size();
    while(i<n && j<m)
    {
        if(t[i]==p[j])//Match
        {
            i++;
            j++;
        }
        else//MisMatch
        {
            if(j!=0)
                j=lps[j-1];
            else//No option left
                i++;
        }
    }
    if(j==m)//able to find the pattern
        return i-m;
    else//Not found
        return -1;
}
int main()
{
    cout<<"Enter Text and Pattern:-"<<endl;
    string text,pattern;
    cin>>text>>pattern;
    int matchedIndex=kmp(text,pattern);
    if(matchedIndex!=-1)
        cout<<"Found at Index="<<matchedIndex<<endl;
    else
        cout<<"Pattern not Present"<<endl;
    return 0;
}

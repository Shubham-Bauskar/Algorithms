#include<bits/stdc++.h>
using namespace std;
void longest_common_substring(string a,string b)
{
    int lookup[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++)
        lookup[i][0]=0;
    for(int j=0;j<=b.size();j++)
        lookup[0][j]=0;
    int ans=0,maxi=-1,maxj=-1;
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[i-1]==b[i-1])//both characters are same so 1 + whatever done so far without considering them
            {
                lookup[i][j]=1+lookup[i-1][j-1];
                if(ans<lookup[i][j])
                {
                    ans=lookup[i][j];
                    maxi=i;
                    maxj=j;
                }
            }
            else
                lookup[i][j]=0;
        }
    }
    cout<<"Length of Longest Common Substring="<<ans<<endl;
    int i=maxi,j=maxj;
    string substring;
    while(lookup[i][j]!=0)
    {
        substring.push_back(a[i-1]);
        i--;
        j--;
    }
    reverse(substring.begin(),substring.end());
    cout<<"SubString="<<substring<<endl;
}
int main()
{
    cout<<"Enter 2 Strings:-"<<endl;
    string a,b;
    cin>>ws>>a>>ws>>b;
    longest_common_substring(a,b);
    return 0;
}


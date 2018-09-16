#include<bits/stdc++.h>
using namespace std;
void longest_palindromic_subsequence(string a)
{
    int lookup[a.size()][a.size()];
    for(int i=0;i<a.size();i++)//Element Itself is a palindrome
        lookup[i][i]=1;
    for(int len=2;len<=a.size();len++)
    {
        for(int i=0;i<=a.size()-len;i++)
        {
            int j=i+len-1;
            if(len==2 && a[i]==a[j])
                lookup[i][j]=2;
            else if(a[i]==a[j])//Ends are same so 2+ what ever best we had done before considering ith & jth element i.e[i+1,j-1]
                lookup[i][j]=2+lookup[i+1][j-1];
            else
                lookup[i][j]=max(lookup[i+1][j],lookup[i][j-1]);
        }
    }
    cout<<"Length of Longest Palindromic Subsequence="<<lookup[0][a.size()-1]<<endl;
    cout<<"Sequence:-"<<endl;
    string lps;
    int i=0,j=a.size()-1;
    while(i!=j)
    {
        int left=lookup[i][j-1];
        int bottom=lookup[i+1][j];
        int curr=lookup[i][j];
        if(curr>bottom && curr>left)
        {
            lps.push_back(a[j]);
            i++;
            j--;
        }
        else if(curr==bottom)
            i++;
        else if(curr==left)
            j--;
    }
    string back=lps;
    lps.push_back(a[i]);
    reverse(back.begin(),back.end());
    cout<<lps<<back<<endl;
}
int main()
{
    string s;
    cout<<"Enter the String:-"<<endl;
    cin>>s;
    longest_palindromic_subsequence(s);
    return 0;
}

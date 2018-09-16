#include<bits/stdc++.h>
using namespace std;
int maximum(int x,int y)
{
    return x<=y?y:x;
}
int longest_palindromic_subsequence(string s,int low,int high)
{
    if(low==high)//1 Length String is always palindrome
        return 1;
    else if(low+1==high && s[low]==s[high])//2 Length String
            return 2;
    //Length of String is greater than or equal to 3
    if(s[low]==s[high])
        return 2+longest_palindromic_subsequence(s,low+1,high-1);
    return maximum(longest_palindromic_subsequence(s,low,high-1),longest_palindromic_subsequence(s,low+1,high));
}
int main()
{
    cout<<"Enter the String:-"<<endl;
    string s;
    cin>>ws>>s;
    cout<<"Length of Longest Palindromic SubSequence="<<longest_palindromic_subsequence(s,0,s.size()-1);
    return 0;
}

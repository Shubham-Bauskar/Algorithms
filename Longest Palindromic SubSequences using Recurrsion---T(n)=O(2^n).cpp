#include<bits/stdc++.h>
using namespace std;
int longest_palindromic_subsequence(string a,int low,int high)
{
    if(low==high)//Only one element
        return 1;
    if(a[low]==a[high] && high==low+1)//Two Elements
        return 2;
    if(a[low]==a[high])
        return 2+longest_palindromic_subsequence(a,low+1,high-1);
    return max(longest_palindromic_subsequence(a,low,high-1),longest_palindromic_subsequence(a,low+1,high));
}
int main()
{
    string s;
    cout<<"Enter the String:-"<<endl;
    cin>>s;
    cout<<"Length of longest Palindromic Subsequence="<<longest_palindromic_subsequence(s,0,s.size()-1);
    return 0;
}


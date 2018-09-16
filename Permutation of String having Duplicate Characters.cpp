// Time Complexity < O(n!)
// Worst case is O(n!) when all characters are distinct
// Best Case is when all characters are same
#include<bits/stdc++.h>
using namespace std;
int ct=0;
void permute(char st[],int a[],int n,char b[],int k,int siz)
{
    if(n==0)//Base Case no slot left to fill
    {
        for(int i=0;i<siz;i++)
            cout<<b[i];
        cout<<endl;
        ct++;
        return;
    }
    // Fill 1st slot and recursively call permute() to fill n-1 left slot
    for(int i=0;i<26;i++)
    {
        if(a[i]>=1)
        {
            a[i]--;//First one Character && then call permute to fix remaining character
            b[k]=i+97;
            permute(st,a,n-1,b,k+1,siz);
            a[i]++;//Release
        }
    }
}
int main()
{
    cout<<"Enter the length of String:-"<<endl;
    int n=7;
    cin>>n;
    char s[n];
    cout<<"Enter the String:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>s[i];
    int a[26];//Array of Count of Characters
    for(int i=0;i<26;i++)
        a[i]=0;
    for(int i=0;i<n;i++)
        a[s[i]-97]++;
    cout<<"Count Array:-"<<endl;
    for(int i=0;i<26;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Permutation:-"<<endl;
    char b[n];
    permute(s,a,n,b,0,n);
    cout<<"Total No. of Permutations="<<ct<<endl;
    return 0;
}

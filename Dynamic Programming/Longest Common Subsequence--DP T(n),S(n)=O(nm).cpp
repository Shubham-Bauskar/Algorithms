#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b)
{
    int lookup[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++)//Base Case when one string is empty so no common subsequence will exists
        lookup[i][0]=0;
    for(int j=0;j<=b.size();j++)//Base Case when one string is empty so no common subsequence will exists
        lookup[0][j]=0;
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[i-1]==b[j-1])//Same character
                lookup[i][j]=1+lookup[i-1][j-1];//1+whatever best we had done so far before considering this character
            else
            {
                lookup[i][j]=max(lookup[i-1][j],lookup[i][j-1]);
                //Whatever is better among if pick character from 1st string & discard character of 2nd String
                // or Pick Character of 2nd String & discard character of 1st string
            }
        }
    }
    cout<<"LookUP:-"<<endl;
    for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
            cout<<lookup[i][j]<<" ";
        cout<<endl;
    }
    //Generating Longest Common SubSequence
    int i=a.size(),j=b.size();
    string lcs_string;
    while(i>0 && j>0)
    {
        int left=lookup[i][j-1];
        int top=lookup[i-1][j];
        int curr=lookup[i][j];
        if(curr>left && curr>top)//At position i,j character of string 1 & string 2 are equal
        {
            lcs_string.push_back(b[j-1]);
            i--;
            j--;
        }
        else if(left==curr)//We reach this position from left
            j--;
        else if(top==curr)//We reach this position from top
            i--;
    }
    reverse(lcs_string.begin(),lcs_string.end());
    cout<<"Longest Common SubSequence="<<lcs_string<<endl;
    return lookup[a.size()][b.size()];
}
int main()
{
    cout<<"Enter the Strings:-"<<endl;
    string a,b;
    cin>>ws>>a>>b;
    cout<<"Length of Longest Common SubSequence="<<lcs(a,b);
    return 0;
}

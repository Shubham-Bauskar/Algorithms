/*
Worst Case=O(n*m)
When at each index we get same value of hashprev and hashpattern
It uses Rolling Hash Function

Effective Hash Function:-
eg:- "abc" hashprev=a*101^0+b*101^1+c*101^2;
for computing next hashprev
hashprev-=s1[i];
hashprev=hashprev/101;
hashprev+=s1[i+k]*101^(s2.size()-1);

Application:-
1 Detecting Plagiarism.
2 Multiple Pattern Search of Same Pattern Length.

Best Case:- Not Found or Only one time hashprev==hashpattern O(n)
Worst Case:-T(n,m)=O(m)+O((n-m+1)*m)==O(n*m)

*/
#include<iostream>
using namespace std;
bool isvalid(string s1,string s2,int i,int j)
{
    int x,y;
    for(x=i,y=0;x<i+j;x++,y++)
    {
        if(s1.at(x)!=s2.at(y))
            return false;
    }
    return true;
}
int main()
{
    string s1,s2;
    cout<<"Enter String:-"<<endl;
    cin>>s1;
    cout<<"Enter Pattern:-"<<endl;
    cin>>s2;
    int k=s2.size();
    int flag=0,i,hashprev=0,hashpattern=0;
    for(int i=0;i<k;i++)
    {
        hashprev+=s1[i];
        hashpattern+=s2[i];
    }
    for(i=0;i<=s1.size()-k;i++)
    {
        if(hashprev==hashpattern)
        {
            if(isvalid(s1,s2,i,k)==true)
            {
                flag=1;
                break;
            }
        }
        else
            hashprev=hashprev-s1[i]+s1[i+k];
    }
    if(flag==1)
        cout<<"Found at Index="<<i<<endl;
    else
        cout<<"Not Found"<<endl;
    return 0;
}

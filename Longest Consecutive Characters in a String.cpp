#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the String:-"<<endl;
    cin>>ws>>s;
    char ans='$';
    int count=0;
    for(int i=0;i<s.size();)
    {
        int temp=1,j=i+1;
        while(s[j]==s[i])
        {
            temp++;
            j++;
        }
        if(temp>count)
        {
            count=temp;
            ans=s[i];
        }
        i=j;
    }
    cout<<"Character:-"<<endl;
    cout<<ans<<"-"<<count;
    return 0;
}

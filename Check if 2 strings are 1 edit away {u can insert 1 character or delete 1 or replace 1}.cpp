#include<bits/stdc++.h>
using namespace std;
bool one_edit_away(string a,string b)
{
    int sta[26]={0};
    int stb[26]={0};
    for(int i=0;i<a.size();i++)
        sta[a[i]-97]++;
    for(int i=0;i<b.size();i++)
        stb[b[i]-97]++;
    int flag=0,a_1=0,b_1=0,ab_2=0;
    //Don't use same array to store char count b/c it can't handle replace cases;
    for(int i=0;i<26;i++)
    {
        if(sta[i]==stb[i])
            continue;
        if(sta[i]==1 && stb[i]==0)
        {
            flag++;
            a_1++;
        }
        if(stb[i]==1 && sta[i]==0)
        {
            flag++;
            b_1++;
        }
        if(stb[i]>1 || sta[i]>1)
            ab_2++;
    }
    if(flag==0)//No Edits Required
        return true;
    if(ab_2>=1)//More than 2 characters to be replaced
        return false;
    if(flag==2 && a_1==1 && b_1==1)//Replace
        return true;
    if((a_1==1 || b_1==1)&& flag==1)//Insert or Delete
        return true;
    return false;
}
int main()
{
    cout<<"Enter 2 Strings:-"<<endl;
    string a,b;
    cin>>a>>b;
    cout<<"1-Edit Away="<<one_edit_away(a,b);
    return 0;
}

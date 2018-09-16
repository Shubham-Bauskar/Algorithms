#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the String:-"<<endl;
    string a;
    cin>>a;
    int n=a.size();
    int st[n][n];//st=1 if character & st=-1 for number
    for(int i=0;i<n;i++)
    {
        if(a[i]>=48 && a[i]<=57)
            st[i][i]=-1;
        else
            st[i][i]=1;
    }
    int max=0,si=-1,ei=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>=48 && a[j]<=57)//Number
                st[i][j]=st[i][j-1]-1;
            else
                st[i][j]=st[i][j-1]+1;
            if(st[i][j]==0)//Equal number of Characters and Numbers
            {
                int len=j-i+1;
                if(max<len)
                {
                    max=len;
                    si=i;
                    ei=j;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<st[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Length of SubArray="<<max<<endl;;
    for(int i=si;i<=ei;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}


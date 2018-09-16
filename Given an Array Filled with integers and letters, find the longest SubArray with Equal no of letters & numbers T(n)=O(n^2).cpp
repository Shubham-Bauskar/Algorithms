#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the String:-"<<endl;
    string a;
    cin>>a;
    int n=a.size();
    int max=0,si=-1,ei=-1;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            if(a[j]>=48 && a[j]<=57)//Number
                sum--;
            else
                sum++;
            if(sum==0)//Equal number of Characters and Numbers
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
    cout<<"Length of SubArray="<<max<<endl;;
    for(int i=si;i<=ei;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}


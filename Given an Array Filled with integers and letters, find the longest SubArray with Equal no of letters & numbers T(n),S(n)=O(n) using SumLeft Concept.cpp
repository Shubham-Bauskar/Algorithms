#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the String:-"<<endl;
    string a;
    cin>>a;
    int n=a.size();
    int sumleft[n];
    sumleft[0]=(a[0]>=48 && a[0]<=57)?-1:1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=48 && a[i]<=57)//+1=char & -1=number
            sumleft[i]=sumleft[i-1]-1;
        else
            sumleft[i]=sumleft[i-1]+1;
    }
    int max=0,si=0,ei=-1;
    //if SubArray containing equal no of char & number starts with index 0
    for(int i=n-1;i>=0;i--)
    {//Traverse from left because we are interested in longest SubArray
        if(sumleft[i]==0)
        {
            max=i+1;
            ei=i;
            break;
        }
    }
    //If SubArray(char==number) starts with index other than 0
    int hash_t[100];
    for(int i=0;i<100;i++)
        hash_t[i]=-1;
    for(int i=0;i<n;i++)
    {
        if(hash_t[sumleft[i]]==-1)//First Time we get this value to store its index
            hash_t[sumleft[i]]=i;
        else//we have already encountered this value
        {
            int len=abs(hash_t[sumleft[i]]-i);
            if(len>max)
            {
                max=len;
                si=hash_t[sumleft[i]]+1;
                ei=i;
            }
        }
    }
    cout<<"Length of SubArray="<<max<<endl;;
    for(int i=si;i<=ei;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}



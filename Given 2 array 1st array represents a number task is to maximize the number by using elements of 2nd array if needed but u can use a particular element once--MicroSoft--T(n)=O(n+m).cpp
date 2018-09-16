#include<bits/stdc++.h>
using namespace std;
int * maximizingnumber(int arr[],int n,int rep[],int m)
{
    int nt[10];
    for(int i=0;i<10;i++)
        nt[i]=0;
    for(int i=0;i<m;i++)
        nt[rep[i]]++;
    int sp=9;
    while(nt[sp]==0)
        sp--;
    for(int i=0;i<n;i++)
    {
        if(sp>=0 && nt[sp]>0 && arr[i]<sp)
        {
            arr[i]=sp;
            nt[sp]--;
            if(nt[sp]<=0)
            {
                while(sp>=0 && nt[sp]==0)
                    sp--;
            }
        }
    }
    return arr;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    maximizingnumber(a,n,b,m);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}


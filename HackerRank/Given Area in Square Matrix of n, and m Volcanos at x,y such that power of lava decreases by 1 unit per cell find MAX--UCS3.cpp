#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;
    while(m--)
    {
        int temp[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            temp[i][j]=0;
        int x,y,w;
        cin>>x>>y>>w;
        for(int p=1;p<=w;p++)
        {
            int av=x-w+p,b=x+w-p,c=y-w+p,d=y+w-p;
            if(av<0)
                av=0;
            if(b>n-1)
                b=n-1;
            if(c<0)
                c=0;
            if(d>n-1)
                d=n-1;
            for(int i=av;i<=b;i++)
                for(int j=c;j<=d;j++)
                        temp[i][j]=p;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]+=temp[i][j];
    }
    int max=a[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
            if(a[i][j]>max)
                max=a[i][j];
        }
        cout<<endl;
    }
    cout<<max<<endl;
    return 0;
}


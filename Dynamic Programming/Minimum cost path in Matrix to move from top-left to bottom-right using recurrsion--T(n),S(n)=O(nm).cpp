#include<bits/stdc++.h>
using namespace std;
int minimum_cost_path(vector<vector<int> > a,int i,int j,int n,int m)
{
    if(i==n-1 && j==m-1)
        return a[n-1][m-1];
    int right=INT_MAX,down=INT_MAX;
    if(i<n-1)
        down=minimum_cost_path(a,i+1,j,n,m);
    if(j<m-1)
        right=minimum_cost_path(a,i,j+1,n,m);
    return a[i][j]+min(right,down);
}
int main()
{
    cout<<"Enter the Number of Rows & Columns:-"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a;
    cout<<"Enter the Weight of Matrix:-"<<endl;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        a.push_back(v);
    }
    cout<<"Minimum Cost Path="<<minimum_cost_path(a,0,0,n,m);
    return 0;
}


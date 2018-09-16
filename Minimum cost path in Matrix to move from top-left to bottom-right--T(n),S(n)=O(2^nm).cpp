#include<bits/stdc++.h>
using namespace std;
void minimum_cost_path(vector<vector<int> > a,int n,int m)
{
    int st[n][m];
    st[0][0]=a[0][0];
    for(int i=1;i<n;i++)
        st[i][0]=st[i-1][0]+a[i][0];
    for(int j=1;j<m;j++)
        st[0][j]=st[0][j-1]+a[0][j];
    for(int i=1;i<n;i++)
    {
        //move from top i.e st[i-1][j]+down
        //move from left i.e st[i][j-1]+left
        //choose which option is best
        for(int j=1;j<m;j++)
            st[i][j]=a[i][j]+min(st[i-1][j],st[i][j-1]);
    }
    cout<<"Minimum Path Cost="<<st[n-1][m-1]<<endl;
    int i=n-1,j=m-1;
    vector<int> path;
    path.push_back(a[i][j]);
    while(i>0 && j>0)
    {
        int x=st[i][j]-a[i][j];
        if(x==st[i-1][j])//come from top
        {
            path.push_back(a[i-1][j]);
            i--;
        }
        else if(x==st[i][j-1])
        {
            path.push_back(a[i][j-1]);
            j--;
        }
    }
    path.push_back(a[0][0]);
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<" ";
    cout<<endl;
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
    minimum_cost_path(a,n,m);
    return 0;
}

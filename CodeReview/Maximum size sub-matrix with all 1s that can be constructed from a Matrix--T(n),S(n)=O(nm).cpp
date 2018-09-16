#include<bits/stdc++.h>
using namespace std;
void minimum_cost_path(vector<vector<int> > a,int n,int m)
{
    //st[i][j] represents no of 1's in SubMatrix[0,0,i,j]
    int st[n][m];
    st[0][0]=a[0][0]==1?1:0;
    for(int i=1;i<n;i++)
        st[i][0]=st[i-1][0]+a[i][0];
    for(int j=1;j<m;j++)
        st[0][j]=st[0][j-1]+a[0][j];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]==1)
                st[i][j]=1+st[i-1][j]+st[i][j-1]-st[i-1][j-1];
            else
                st[i][j]=st[i-1][j]+st[i][j-1]-st[i-1][j-1];
        }
    }
    int i
}
int main()
{
    cout<<"Enter the Number of Rows & Columns:-"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a;
    cout<<"Enter the Matrix:-"<<endl;
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


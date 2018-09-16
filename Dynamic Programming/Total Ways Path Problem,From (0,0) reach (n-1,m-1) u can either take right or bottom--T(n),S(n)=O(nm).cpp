#include<bits/stdc++.h>
using namespace std;
int no_of_ways(int r,int c)
{
    int lookup[r][c];
    for(int i=0;i<r;i++)//Base Case their is only on way take bottom
        lookup[i][0]=1;
    for(int i=0;i<c;i++)//Take only Right
        lookup[0][i]=1;
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)//No of ways to reach [i,j] is reach [i-1][j] & take bottom + reach [i][j-1] & take Right
            lookup[i][j]=lookup[i-1][j]+lookup[i][j-1];
    }
    return lookup[r-1][c-1];
}
int main()
{
    cout<<"Enter No. of Rows & Column:-"<<endl;
    int r,c;
    cin>>r>>c;
    cout<<"No. of Ways to Reach (n-1,m-1) from (0,0)="<<no_of_ways(r,c);
    return 0;
}

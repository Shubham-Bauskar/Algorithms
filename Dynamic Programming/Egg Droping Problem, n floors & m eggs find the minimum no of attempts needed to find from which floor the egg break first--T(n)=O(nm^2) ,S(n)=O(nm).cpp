#include<bits/stdc++.h>
using namespace std;
int eggs_drop_floors(int m,int n)
{
    int lookup[m+1][n+1];
    for(int i=0;i<=m;i++)//If x eggs are left & 0 floors are to be test then no of attempts=0
        lookup[i][0]=0;
    for(int j=0;j<=n;j++)//If we have 1 egg and x floors no of attempts=x
    {
        lookup[0][j]=0;
        lookup[1][j]=j;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //We have i eggs and j floors
            if(i>j)
                lookup[i][j]=lookup[i-1][j];
            else
            {
                int min=INT_MAX;
                int x;
                for(int f=1;f<=j;f++)
                {
                    x=1+max(lookup[i-1][f-1],lookup[i][j-f]);
                    if(x<min)
                        min=x;
                }
                lookup[i][j]=min;
            }
        }
    }
    return lookup[m][n];
}
int main()
{
    cout<<"Enter the Number of Floors:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Number of Eggs:-"<<endl;
    int m;
    cin>>m;
    cout<<"Minimum No. of Attempts Needed to Find="<<eggs_drop_floors(m,n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Rows & Columns:-"<<endl;
    int n,m;
    cin>>n>>m;
    int a[n][m];
    cout<<"Enter the Elements:-"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    //Memorization
    int precompute[n][m];
    precompute[0][0]=a[0][0];
    for(int i=1;i<n;i++)
        precompute[i][0]=precompute[i-1][0]+a[i][0];
    for(int j=1;j<m;j++)
        precompute[0][j]=precompute[0][j-1]+a[0][j];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
            precompute[i][j]=precompute[i-1][j]+precompute[i][j-1]-precompute[i-1][j-1]+a[i][j];
    }
    cout<<"PreCompute:-"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<precompute[i][j]<<" ";
        cout<<endl;
    }
    int max=INT_MIN;
    int row1=-1,row2=-1,col1=-1,col2=-1;
    for(int r1=0;r1<n;r1++)
    {
        for(int r2=0;r2<n;r2++)
        {
            for(int c1=0;c1<m;c1++)
            {
                for(int c2=0;c2<m;c2++)
                {
                    int sum=precompute[r2][c2]-precompute[r1][c1]-precompute[r2][c1]+precompute[r1][c1];
                    if(sum>max)
                    {
                        max=sum;
                        row1=r1;
                        row2=r2;
                        col1=c1;
                        col2=c2;
                    }
                }
            }
        }
    }
    cout<<"Max Sum="<<max<<endl;
    cout<<"SubMatrix="<<row1<<" "<<row2<<" "<<col1<<" "<<col2<<endl;
    return 0;
}
/*
Test Case
9 -8 1 3 -2
-3 7 6 -2 4
6 -4 -4 8 -7
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter No. of Rows & Columns of the Grid:-"<<endl;
    int r,c;
    cin>>r>>c;
    int maze[r][c];
    cout<<"Enter 0 if Cell is not Blocked,1 if Cell is Blocked"<<endl;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>maze[i][j];
    cout<<"No. of Possible Paths to Reach [n-1,m-1] From [0,0]=";
    int count[r][c];
    for(int i=0;i<r;i++)//Initially all Paths are Blocked
        for(int j=0;j<c;j++)
            count[i][j]=0;
    for(int i=0;i<r;i++)//Only One way go Down if the cell is blocked then break;
    {
        if(maze[i][0]==0)
            count[i][0]=1;
        else
            break;
    }
    for(int j=0;j<c;j++)//Only One way go Right if the cell is blocked then break;
    {
        if(maze[0][j]==0)
            count[0][j]=1;
        else
            break;
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)//To reach [i,j] cell first reach [i-1,j] cell or reach [i,j-1] cell
        {
            if(maze[i][j]==0)//Cell is not Blocked
               count[i][j]=count[i-1][j]+count[i][j-1];
            else
               count[i][j]=0;//Since Cell is Blocked we cannot proceed further from that cell
        }
    }
    cout<<count[r-1][c-1]<<endl;
    cout<<"LookUP Matrix:-"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<count[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the Rows & Columns:-"<<endl;
    cin>>n>>m;
    int a[n][m],st[n][m];
    cout<<"Enter the Matrix 0=water & +ve=Land :-"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            st[i][j]=1;//1=Not Visited,0=Visited,2=In stack
        }
    }
    vector<int> area;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0 && st[i][j]==1)//Water is Present and not visited already
            {
                int count=0;
                int stki[100],stkj[100],top=-1;
                stki[++top]=i;
                stkj[top]=j;
                st[i][j]=0;
                while(top!=-1)//Not Empty
                {
                    int x=stki[top];
                    int y=stkj[top--];
                    count++;
                    st[x][y]=0;
                    if(x<=n-1 && y<m-1 && st[x][y+1]==1 && a[x][y+1]==0)//E is not visited & it contains water
                    {
                        stki[++top]=x;
                        stkj[top]=y+1;
                        st[x][y+1]=2;//In stack
                    }
                    if(x<n-1 && y<=m-1 && st[x+1][y]==1 && a[x+1][y]==0)//S
                    {
                        stki[++top]=x+1;
                        stkj[top]=y;
                        st[x+1][y]=2;//In stack
                    }
                    if(x<n-1 && y<m-1 && st[x+1][y+1]==1 && a[x+1][y+1]==0)//SE
                    {
                        stki[++top]=x+1;
                        stkj[top]=y+1;
                        st[x+1][y+1]=2;//In stack
                    }
                    if(x>0 && y>0 && st[x-1][y-1]==1 && a[x-1][y-1]==0)//NW
                    {
                        stki[++top]=x-1;
                        stkj[top]=y-1;
                        st[x-1][y-1]=2;//In stack
                    }
                    if(x>0 && y>=0 && st[x-1][y]==1 && a[x-1][y]==0)//N
                    {
                        stki[++top]=x-1;
                        stkj[top]=y;
                        st[x-1][y]=2;//In stack
                    }
                    if(x>=0 && y>0 && st[x][y-1]==1 && a[x][y-1]==0)//W
                    {
                        stki[++top]=x;
                        stkj[top]=y-1;
                        st[x][y-1]=2;//In stack
                    }
                    if(x<n-1 && y>0 && st[x+1][y-1]==1 && a[x+1][y-1]==0)//SW
                    {
                        stki[++top]=x+1;
                        stkj[top]=y-1;
                        st[x+1][y-1]=2;//In stack
                    }
                    if(x>0 && y<m-1 && st[x-1][y+1]==1 && a[x-1][y+1]==0)//NE
                    {
                        stki[++top]=x-1;
                        stkj[top]=y+1;
                        st[x-1][y+1]=2;//In stack
                    }
                }
                area.push_back(count);
            }
        }
    }
    cout<<"Area of All Ponds:-"<<endl;
    if(area.size()==0)
        cout<<"0"<<endl;
    else
    {
        for(int i=0;i<area.size();i++)
            cout<<area[i]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
Test Case:-
5 6
0 0 0 1 1 1
1 1 1 0 0 0
1 1 1 1 1 0
0 0 1 1 1 1
1 1 1 0 0 0
*/

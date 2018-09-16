#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter No. of Rows & Columns:-"<<endl;
    int n,m;
    cin>>n>>m;
    int a[n][m];
    cout<<"Enter the Elements of the Matrix:-"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    int left=0,right=0;
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i]=0;
    int max_sum=0,max_left=-1,max_right=-1,max_up=-1,max_down=-1;
    for(int left=0;left<m;left++)
    {
        for(int right=left;right<m;right++)
        {
            for(int i=0;i<n;i++)
                temp[i]+=a[i][right];
            int max_here=0,max_so_far=INT_MIN;
            int start=-1,end=-1,s=0;
            for(int i=0;i<n;i++)
            {
                max_here+=temp[i];
                if(max_here<0)
                {
                    max_here=0;
                    s=i+1;
                }
                if(max_here>max_so_far)
                {
                    max_so_far=max_here;
                    start=s;
                    end=i;
                }
            }
            if(max_so_far>max_sum)
            {
                max_sum=max_so_far;
                max_left=left;
                max_right=right;
                max_up=start;
                max_down=end;
            }
        }
        for(int i=0;i<n;i++)
            temp[i]=0;
    }
    cout<<"Maximum Sum SubRectangle="<<max_sum<<endl;
    cout<<"SUB MATRIX:-"<<endl;
    for(int i=max_up;i<=max_down;i++)
    {
        for(int j=max_left;j<=max_right;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

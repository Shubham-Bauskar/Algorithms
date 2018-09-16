#include<bits/stdc++.h>
using namespace std;
int binary_search_column(vector<int> a[],int row,int key,int column)
{
    int low=0,high=column-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[row][mid]==key)
            return mid;
        else if(a[row][mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    cout<<"Enter the Number of Rows & Columns of Matrix:-"<<endl;
    int r,c;
    cin>>r>>c;
    cout<<"Enter the Elements in the Matrix:-"<<endl;
    vector<int> a[r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    cout<<"Enter the Elements to Found:-"<<endl;
    int key;
    cin>>key;
    int flag=0;
    for(int i=0;i<r;i++)//For Each Row,Binary Search that Column if may lie in that row i.e key is in range a[row][0] a[row][column]
    {
        int pos_col=binary_search_column(a,i,key,c);
        if(pos_col!=-1)
        {
            cout<<"Found at Row="<<i<<" "<<"Column="<<pos_col<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"Element Not Found"<<endl;
    return 0;
}

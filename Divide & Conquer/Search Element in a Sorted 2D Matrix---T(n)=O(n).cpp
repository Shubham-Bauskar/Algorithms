#include<bits/stdc++.h>
using namespace std;
pair<int,int> search(vector<int> a[],int row,int column,int key)
{
    int i=0,j=column-1;
    while(i<row && j>=0)
    {
        if(a[i][j]==key)
            return pair<int,int>(make_pair(i,j));
        else if(a[i][j]>key)//Since the element a[i][j] is greater then key so the key may be present in that row only so column--
            j--;
        else//if a[i][j]>key then search in next row i.e row++
            i++;
    }
    return pair<int,int>(make_pair(-1,-1));
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
    pair<int,int> p=search(a,r,c,key);
    if(p.first!=-1 && p.second!=-1)//Found
        cout<<"Found at Row="<<p.first<<" "<<"Column="<<p.second<<endl;
    else
        cout<<"Not Found"<<endl;
    return 0;
}
/* Test Cases
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
*/


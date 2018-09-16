#include<bits/stdc++.h>
using namespace std;
void as_close_as_possible(int n,int k,int a[])
{
    int lookup[n][k+1];
    for(int i=0;i<n;i++)//if weight==0 we cannot select any item.
        lookup[i][0]=0;
    for(int j=0;j<=k;j++)//If only one item is their select that item any no of time such that weight of all items is as closer to expected weight(k)
        lookup[0][j]=a[0]*(j/a[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(a[i]>j)//We cannot select element 'i'
                lookup[i][j]=lookup[i-1][j];//whatever best we had done so far
            else//We can select item 'i'
                lookup[i][j]=max(lookup[i-1][j],a[i]+lookup[i][j-a[i]]);
            //max(select,not select)
        }
    }
    cout<<"LookUP:-"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
            cout<<lookup[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Max Sum Obtained:-"<<endl;
    cout<<lookup[n-1][k]<<endl;
}
int main()
{
    cout<<"Enter No. of Elements:-"<<endl;
    int n,k;
    cin>>n;
    cout<<"Enter the Elements:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Expected Weight:-"<<endl;
    cin>>k;
    as_close_as_possible(n,k,a);
    return 0;
}

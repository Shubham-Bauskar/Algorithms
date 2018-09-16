#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the size of 2 Arrays:-"<<endl;
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    cout<<"Enter the elements in Arrays:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    cout<<"Common Elements:-"<<endl;
    int last_index_matched=-1,count=0;
    for(int i=0;i<n;i++)
    {
        int j=last_index_matched+1;
        while(j<m && b[j]<a[i])
            j++;
        if(b[j]==a[i])
        {
            last_index_matched=j;
            count++;
        }
        else
            break;
    }
    cout<<"Count="<<count<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int count=0;
    int index=-1;
};
int main()
{
    cout<<"Enter the number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    map<int,node> m;
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(m.find(a[i])!=m.end())//already exists
            m[a[i]].count++;
        else
        {
            struct node p;
            p.count=1;
            p.index=i;
            m.insert(make_pair(a[i],p));
        }
    }
    int index=n;
    for(int i=0;i<m.size();i++)
    {
        struct node p=m[i];
        if(p.count==1)
            cout<<m[i].first<<endl;
    }
    return 0;
}

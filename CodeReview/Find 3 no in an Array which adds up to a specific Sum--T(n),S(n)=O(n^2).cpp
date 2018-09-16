#include<bits/stdc++.h>
#include<ext/hash_map>
using namespace std;
struct number
{
    int a=-1;
    int b=-1,c=-1;
};
struct point
{
    int x;
    int y;
};
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Sum:-"<<endl;
    int sum;
    cin>>sum;
    vector<struct number> v;
    __gnu_cxx::hash_map<int,struct point> hm;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sp=a[i]+a[j];
            struct point temp;
            temp.x=i;
            temp.y=j;
            hm.insert(pair<int,struct point>(sp,temp));
        }
    }
    for(int i=0;i<n;i++)
    {
        if(hm.find(sum-a[i])!=hm.end())
        {
             __gnu_cxx::hash_map<int,struct point>::iterator p;
            p= hm.find(sum-a[i]);
            struct number nm;
            nm.a=i;
            nm.b=(p->second).x;
            nm.c=(p->second).y;
            v.push_back(nm);
        }
    }
    cout<<"No. of Elements such that a[i]+a[j]+a[k]==sum:-"<<endl;
    for(int i=0;i<v.size();i++)
        cout<<a[v[i].a]<<" "<<a[v[i].b]<<" "<<a[v[i].c]<<endl;
    cout<<endl;
    return 0;
}


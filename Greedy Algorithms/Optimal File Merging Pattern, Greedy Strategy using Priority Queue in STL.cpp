#include<bits/stdc++.h>
using namespace std;
int optimal_file_merge(int a[],int n)
{
    priority_queue<int,vector<int>,greater<int> > pq(a,a+n);
    int cost=0;
    while(pq.size()>1)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        cost+=x+y;
        pq.push(x+y);
    }
    return cost;
}
int main()
{
    cout<<"Enter the Number of Files:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the File Size:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cost=optimal_file_merge(a,n);;
    cout<<"Cost to Merge N Files is="<<cost<<endl;
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,vector<int> > m;
    vector<int> p;
    p.push_back(10);
    p.push_back(20);
    m.insert(make_pair(1,p));
    m[1].push_back(30);
    m[1].push_back(40);
    vector<int> q=m[1];
    for(int i=0;i<q.size();i++)
        cout<<q[i]<<endl;
    return 0;
}

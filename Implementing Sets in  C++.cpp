#include<bits/stdc++.h>
using namespace std;
int main()
{
    // SETS:-
    cout<<"SETS:-"<<endl;
    set<int,greater<int> > s;
    for(int i=1;i<=25;i++)
        s.insert(i);
    set<int,greater<int> >::iterator p,q;
    for(p=s.begin();p!=s.end();p++)
        cout<<*p<<" ";
    q=s.find(20);
    cout<<endl<<"Element Found:-";
    cout<<endl<<*q<<endl;

    // MAPS:-
    cout<<endl<<"MAPS:-"<<endl;
    map<int,char> m;
    for(int i=1;i<=25;i++)
        m.insert(pair<int,char>(i,i+64));
    map<int,char>::iterator t,v;
    for(t=m.begin();t!=m.end();t++)
        cout<<t->first<<"-"<<t->second<<endl;
    v=m.find(18);
    cout<<"Element Found:-";
    cout<<endl<<v->first<<"-"<<v->second;
    return 0;
}

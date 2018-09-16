#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the No. of People:-"<<endl;
    cin>>n;
    vector<int> birth,death;
    cout<<"Enter the Birth & Death Year:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int b,d;
        cin>>b>>d;
        birth.push_back(b);
        death.push_back(d);
    }
    int alive[101];
    for(int i=0;i<=100;i++)
        alive[i]=0;
    //For each birth in year bi increment # of alive in year bi by 1
    //For each death in year di decrement # of alive in year di by 1
    for(int i=0;i<n;i++)
    {
        alive[birth[i]]++;
        alive[death[i]+1]--;//If a person is dead in year d then also it is counted as alive in year d, but from later year it is counted as dead
    }
    int max=0,curr_alive=0,max_alive_year=-1;
    for(int i=0;i<=100;i++)
    {
        curr_alive+=alive[i];
        if(curr_alive>max)
        {
            max=curr_alive;
            max_alive_year=i;
        }
    }
    cout<<"Year in Which Max Population is Alive="<<1900+max_alive_year<<endl;
    return 0;
}
/*
Test Cases:-
n=14

4 32
7 21
6 41
7 92
8 92
1 12
10 12
11 17
18 22
9 79
8 81
9 19
7 76
8 41
*/

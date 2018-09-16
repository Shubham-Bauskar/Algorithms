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
    sort(birth.begin(),birth.end());
    sort(death.begin(),death.end());
    int max_val=0,curr_alive=0,max_alive_year=-1;
    int bi=0,di=0;
    //For each birth increment # of alive by 1
    //For each death decrement # of alive by 1
    while(bi<birth.size())
    {
       if(birth[bi]<=death[di])//if birth[bi]==death[di] then acc to qn that person is considered to be alive
       {
           curr_alive++;
           if(curr_alive>max_val)
           {
               max_val=curr_alive;
               max_alive_year=birth[bi];
           }
           bi++;
       }
       if(birth[bi]>death[di])
       {
           curr_alive--;
           di++;
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

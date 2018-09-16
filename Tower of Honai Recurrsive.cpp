#include<bits/stdc++.h>
using namespace std;
void towerofhonai(int n,char beg,char aux,char last)
{
    if(n>0)
    {
        towerofhonai(n-1,beg,last,aux);
        cout<<beg<<"->"<<last<<endl;
        towerofhonai(n-1,aux,beg,last);
    }
}
int main()
{
    cout<<"Enter Number of Plates:-"<<endl;
    int n;
    cin>>n;
    cout<<"A: Beginning,B: Auxillary,C: End"<<endl;
    cout<<"Steps:-"<<endl;
    towerofhonai(n,'A','B','C');
    return 0;
}

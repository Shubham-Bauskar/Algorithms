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
    int bin[10];//Divide 100 years[1900-2000] in bins of size 10 i.e bin[0]=[1900,1910] & bin[5]=[51-60]
    for(int i=0;i<10;i++)
        bin[i]=0;
    for(int i=0;i<n;i++)
    {
          int x=birth[i]/10;
          int y=death[i]/10;
          for(int j=x;j<=y;j++)
            bin[j]=bin[j]+1;
    }
    cout<<"Bin of 10 years:-"<<endl;
    for(int j=0;j<10;j++)
        cout<<bin[j]<<" ";
    cout<<endl;
    int max=bin[0],maxi=0;
    for(int i=1;i<10;i++)
    {
        if(max<bin[i])
        {
            max=bin[i];
            maxi=i;
        }
    }
    int yi=maxi*10+1;
    int yf=(maxi+1)*10;
    for(int i=0;i<10;i++)
        bin[i]=0;
    for(int i=0;i<n;i++)
    {
        int x=birth[i];
        int y=death[i];
        if(yi<=x && y<=yf)
        {
            for(int j=x;j<=y;j++)
                bin[j-yi]++;
        }
        else if(x<=yi && yf<=y)
        {
            for(int j=yi;j<=yf;j++)
                bin[j-yi]++;
        }
        else if(x<=yi && y<=yf)
        {
            for(int j=yi;j<=y;j++)
                bin[j-yi]++;
        }
        else if(yi<=x && yf<=y)
        {
            for(int j=x;j<=yf;j++)
                bin[j-yi]++;
        }
    }
    cout<<"Bin of Each Year:-"<<endl;
    for(int i=0;i<10;i++)
        cout<<bin[i]<<" ";
    cout<<endl;
    max=bin[0];
    maxi=0;
    for(int i=1;i<10;i++)
    {
        if(max<bin[i])
        {
            max=bin[i];
            maxi=i;
        }
    }
    cout<<"Year in Which Max Population is Alive="<<yi+maxi<<endl;
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

#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
};
struct slope
{
    float s;
    int count;
    float intersept;
};
int main()
{
    cout<<"Enter the Number of Points:-"<<endl;
    int n;
    cin>>n;
    struct point g[n];
    cout<<"Enter the Coordinates of Each Point:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>g[i].x>>g[i].y;
    vector<struct slope> v;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //Calculate the slope of 2 points i-th & j-th
            float xp=g[i].x-g[j].x;
            float tslope=0,tintersept=0;
            if(xp==0)
            {
                tslope=INFINITY;
                tintersept=g[i].x;
            }
            else
            {
                tslope=(g[i].y-g[j].y)/xp;
                tintersept=g[i].y-tslope*g[i].x;
            }
            if(v.size()==0)//If slope Array is Empty then it is a first pair
            {
                struct slope st;
                st.s=tslope;
                st.count=1;
                st.intersept=tintersept;
                v.push_back(st);
            }
            else
            {//Traverse the slope vector to find out if we had already computed the slope of this Type of pair
                int flag=1;
                for(int t=0;t<v.size();t++)
                {
                    if(v[t].s==tslope && v[t].intersept==tintersept)
                    {
                        v[t].count=v[t].count+1;
                        flag=0;
                        break;
                    }
                }
                if(flag==1)//Not Computed Earlier so store it in slope array
                {
                    struct slope st;
                    st.s=tslope;
                    st.count=1;
                    st.intersept=tintersept;
                    v.push_back(st);
                }
            }
        }
    }
    cout<<"Equation of Line:-"<<endl;
    float max=v[0].count,slop=v[0].s,inter=v[0].intersept;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].count>max)
        {
            max=v[i].count;
            slop=v[i].s;
            inter=v[i].intersept;
        }
    }
    if(slop!=INFINITY)
        cout<<"y="<<slop<<"x+"<<inter<<endl;
    else
        cout<<"x="<<inter<<endl;
    return 0;
}
/*
Test Case
n=7
1 2
3 4
3 3
5 6
2 0
6 2
8 6

line:- "y=x+1"
*/

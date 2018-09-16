#include<bits/stdc++.h>
using namespace std;
pair<float,float> compute_geo_center(int x1,int y1,int x2,int y2)
{
    pair<float,float> p;
    p.first=(x1+x2)/2.0;
    p.second=(y1+y2)/2.0;
    return p;
}
int main()
{
    cout<<"Enter the Coordinates of First Square:-"<<endl;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<"Enter the Coordinates of Second Square:-"<<endl;
    int x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;
    pair<float,float> p1,p2;
    p1=compute_geo_center(x1,y1,x2,y2);
    p2=compute_geo_center(x3,y3,x4,y4);
    cout<<"Equation of Line:-"<<endl;
    if(p1.first==p2.first && p1.second==p2.second)//Both Squares have same geometric center
    {
        float slope=p2.second*1.0/p2.first;
        cout<<"y="<<slope<<"x"<<endl;
    }
    else//Different Geometric Square
    {
        if(p1.first==p2.first)//Line is parallel to y-axis
            cout<<"y="<<p1.first<<endl;
        else
        {
            //Compute the Equation of the Line
            float slope=(p2.second-p1.second)*1.0/(p2.first-p1.first);
            float intercept=p2.second-slope*p2.first;
            cout<<"y="<<slope<<"x + "<<intercept<<endl;
        }
    }
    return 0;
}

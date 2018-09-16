#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter First Line(x1,y1) (x2,y2):-"<<endl;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<"Enter Second Line(x3,y3) (x4,y4):-"<<endl;
    int x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;
    float m1=(y2-y1)*1.0/(x2-x1);
    float m2=(y4-y3)*1.0/(x4-x3);
    cout<<"Slope of Line1="<<m1<<endl;
    cout<<"Slope of Line2="<<m2<<endl;
    if(m1==m2)
        cout<<"PARALLEL LINES"<<endl;
    else
    {
        float c1=y1-m1*x1;
        cout<<"C1="<<c1<<endl;
        float c2=y3-m2*x3;
        cout<<"C2="<<c2<<endl;
        float xp,yp;
        xp=(c2-c1)/(m1-m2);
        yp=m1*xp+c1;
        cout<<"Point of Intersection="<<xp<<" "<<yp<<endl;
    }
    return 0;
}

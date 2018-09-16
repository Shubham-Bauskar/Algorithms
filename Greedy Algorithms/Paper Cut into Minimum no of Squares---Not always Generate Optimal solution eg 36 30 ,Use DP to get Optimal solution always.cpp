#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Length & Breadth of Paper:-"<<endl;
    int l,b;
    cin>>l>>b;
    int no_square=0;
    cout<<"Dimension of Square Cut:-"<<endl;
    while(l>0 && b>0)
    {
        if(l>=b)//Length is greater than breadth
        {
            cout<<b<<endl;
            l-=b;
            no_square++;
        }
        else
        {
            cout<<l<<endl;
            b-=l;
            no_square++;
        }
    }
    cout<<"Minimum no of Square Formed="<<no_square<<endl;
    return 0;
}

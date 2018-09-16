#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,counts;
    cin>>t;
    while(t--)
    {
        int k,a,b;
        cin>>k>>a>>b;
        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        if((b-a)>(k/2.0))
            counts=k-(b-a)-1;
        else if((b-a)<(k/2.0))
            counts=(b-a)-1;
        else
            counts=0;
        cout<<counts<<endl;
    }
    return 0;
}

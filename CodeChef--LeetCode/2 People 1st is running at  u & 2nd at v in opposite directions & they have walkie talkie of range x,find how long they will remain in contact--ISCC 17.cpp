#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        float u,v,x;
        cin>>u>>v>>x;
        float ans=x/(u+v);
        printf("%f\n",ans);
    }
    return 0;
}

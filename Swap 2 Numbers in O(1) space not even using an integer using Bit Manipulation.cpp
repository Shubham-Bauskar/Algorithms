#include<bits/stdc++.h>
using namespace std;
void method1(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<a<<" "<<b<<endl;
}
void method2(int a,int b)
{
    a=a-b;
    b=a+b;
    a=b-a;
    cout<<a<<" "<<b<<endl;
}
void bitmanipulation(int a,int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b<<endl;
}
int main()
{
    cout<<"Enter the 2 Number:-"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"M1="<<method1(a,b);
    cout<<"M2="<<method2(a,b);
    cout<<"Bit Manipulation="<<bitmanipulation(a,b);
    return 0;
}

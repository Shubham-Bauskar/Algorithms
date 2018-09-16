#include<bits/stdc++.h>
using namespace std;
int repeatingelement(int a[],int n)
{
    int x=a[0];
    for(int i=1;i<n;i++)
        x=x^a[i];//Using Bit Manipulation & Properties of XOR
    return x;
}
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Repeating Element:-"<<endl;
    cout<<repeatingelement(a,n);
    return 0;
}
// a^a=0
// 0^a=a

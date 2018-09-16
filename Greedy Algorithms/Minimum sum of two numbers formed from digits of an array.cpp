#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    vector<int> v;
    cout<<"Enter the Elements:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int num1=0,num2=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            num1=num1*10+v[i];
        else
            num2=num2*10+v[i];
    }
    cout<<"NUM1="<<num1<<" "<<"NUM2="<<num2<<endl;
    cout<<"Smallest Number Possible:-"<<endl;
    cout<<num1+num2<<endl;
    return 0;
}

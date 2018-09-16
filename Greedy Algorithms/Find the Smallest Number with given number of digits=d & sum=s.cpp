#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter Digits & Sum:-"<<endl;
    int digit,sum;
    cin>>digit>>sum;
    int a[digit];
    a[0]=1;
    sum--;
    for(int i=1;i<digit;i++)
        a[i]=0;
    for(int i=digit-1;i>=0;i--)
    {
        if(sum>9)
        {
            a[i]=9;
            sum-=9;
        }
        else
        {
            a[i]+=sum;
            sum=0;
        }
        if(sum==0)
            break;
    }
    cout<<"Smallest Number with given Sum & Digit:-"<<endl;
    for(int i=0;i<digit;i++)
        cout<<a[i];
    return 0;
}

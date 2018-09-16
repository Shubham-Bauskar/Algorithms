#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int count=0;
    cout<<"Enter the Number:-"<<endl;
    cin>>n;
    while(n!=0)
    {
        if(n%2!=0)
            count++;
        n=n/2;
    }
    cout<<"No of Set Bits:-"<<count;
    return 0;
}
//Can be Solved using Brian Kernighan's Algorithm
//In Worst Case both Sol has T(n)=O(log(n))

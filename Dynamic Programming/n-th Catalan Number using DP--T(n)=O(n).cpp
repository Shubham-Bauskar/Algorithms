#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Value of N:-"<<endl;
    cin>>n;
    unsigned long int cat=1;
    for(int i=2;i<n;i++)
        cat=cat*(4*i-2)/(i+1);
    cout<<"N-th Catalan Number="<<cat<<endl;
    return 0;
}

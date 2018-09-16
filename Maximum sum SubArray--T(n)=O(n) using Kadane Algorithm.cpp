#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum=a[0],maxcurr=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i]+maxcurr)
            maxcurr=a[i];
        else
            maxcurr+=a[i];
        if(maxcurr>sum)
            sum=maxcurr;
    }
    cout<<"Maximum Sum SubArray="<<sum<<endl;
    return 0;
}


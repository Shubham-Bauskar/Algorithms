#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements of the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cout<<"Enter the Size of Set:-"<<endl;
    cin>>m;
    int rand_set[m];
    for(int i=0;i<m;i++)
        rand_set[i]=a[i];
    for(int i=m;i<n;i++)
    {
        int pos=rand()%i;
        if(pos<m)
            rand_set[pos]=a[i];
    }
    cout<<"Random Set:-"<<endl;
    for(int i=0;i<m;i++)
        cout<<rand_set[i]<<" ";
    cout<<endl;
    return 0;
}

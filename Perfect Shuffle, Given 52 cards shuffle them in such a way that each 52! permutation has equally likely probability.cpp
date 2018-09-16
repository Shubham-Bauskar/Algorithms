#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main()
{
    int a[52];
    for(int i=0;i<52;i++)
        a[i]=i+1;
    for(int i=51;i>=0;i--)
    {
        int pos=rand()%(i+1);
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
    }
    cout<<"Perfect shuffle:-"<<endl;
    for(int i=0;i<52;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

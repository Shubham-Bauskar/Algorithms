#include<bits/stdc++.h>
using namespace std;
pair<int,int> findmissing(int a[],int n)
{
    pair<int,int> p;
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    int zor=a[0];
    for(int i=1;i<n;i++)
        zor=zor^a[i];
    for(int i=1;i<=n;i++)
        zor=zor^i;
    for(int i=1;i<=n;i++)
    {
        int b=n*(n+1)*1.0/2-sum+i;
        cout<<b<<endl;
        if(i^b==zor)
            return make_pair(i,b);
    }
}
int main()
{
    cout<<"Enter the Number of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    pair<int,int> p=findmissing(a,n);
    cout<<"Missing Number="<<p.first<<" "<<p.second<<endl;
    return 0;
}
/*
9 1 3 7 5 5 8 2 4(op=5,6)
*/

#include<bits/stdc++.h>
using namespace std;
int countways=0;
void generate_possible(int a[],int n,int p,int k,int l)
{
    if(p==n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                sum+=k;
            else if(a[i]==1)
                sum+=l;
        }
        cout<<sum<<endl;
        countways++;
        return;
    }
    a[p]=0;
    generate_possible(a,n,p+1,k,l);
    a[p]=1;
    generate_possible(a,n,p+1,k,l);
}
int main()
{
    cout<<"Enter Number of Woods:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    int p=0;
    cout<<"Enter Shorter Wood Length & Longer Wood Length:-"<<endl;
    int k,l;
    cin>>k>>l;
    cout<<"All Possible Values:-"<<endl;
    generate_possible(a,n,p,k,l);
    cout<<"No. of Ways="<<countways<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t=0;
void powerset(int a[],int l,int n,int st[])
{
    if(l==n)//Base Condition
    {
       cout<<"{ ";
       t++;
       for(int i=0;i<n;i++)
       {
           if(st[i]==1)
            cout<<a[i]<<" ";
       }
       cout<<"}"<<endl;
       return;
    }
    powerset(a,l+1,n,st);//a[l] is not included
    st[l]=1;// Set status of a[l] to 1 so as to include it in set
    powerset(a,l+1,n,st);//a[l] is included
    st[l]=0;// Reset Status of a[l]
}
int main()
{
    cout<<"Enter Number of Elements in a Set:-"<<endl;
    int n;
    cin>>n;
    int a[n],st[n];
    cout<<"Enter the Elements in the Set:-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        st[i]=0;
    }
    cout<<"All Possible Subsets:-"<<endl;
    powerset(a,0,n,st);
    cout<<"Number of Possible SubSets="<<t<<endl;
    return 0;
}

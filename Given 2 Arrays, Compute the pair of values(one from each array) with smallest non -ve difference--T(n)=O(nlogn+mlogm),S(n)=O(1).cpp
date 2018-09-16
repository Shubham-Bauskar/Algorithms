#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Elements in both the Array:-"<<endl;
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    cout<<"Enter the Elements in Array1:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Elements in Array2:-"<<endl;
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int min=INT_MAX;
    int i=0,j=0;
    while(i<n && j<m)
    {
        int temp=abs(a[i]-b[j]);
        if(temp<min)
            min=temp;
        if(a[i]<b[j])
            i++;
        else
            j++;
    }
    cout<<"Minimum Difference="<<min<<endl;
    return 0;
}


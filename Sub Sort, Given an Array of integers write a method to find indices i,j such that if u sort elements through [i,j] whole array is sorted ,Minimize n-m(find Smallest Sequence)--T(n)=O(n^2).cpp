#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i=0,j=n-1;
    while(i<=j)
    {
        //Compute Maximum & Minimum Element in the Array[i,j];
        int max=a[i],min=a[i];
        for(int x=i+1;x<=j;x++)
        {
            if(max<a[x])
                max=a[x];
            if(min>a[x])
                min=a[x];
        }
        if(a[i]==min && a[j]==max)//This index should be excluded b/c the contains correct element
        {
            i++;
            j--;
        }
        else if(a[i]==min)//i-th index must be excluded b/c it posses correct element
            i++;
        else if(a[j]==max)//j-th index must be excluded b/c it posses correct element
            j--;
        else//Both i-th & j-th index does not posses correct element
            break;
    }
    cout<<"SubArray Needed to Sort[i,j]="<<i<<" "<<j<<endl;
    return 0;
}

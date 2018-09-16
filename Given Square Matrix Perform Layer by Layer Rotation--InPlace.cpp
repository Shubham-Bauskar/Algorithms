#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the value of n:-"<<endl;
    int n;
    cin>>n;
    int a[n][n];
    cout<<"Enter the Elements in the Matrix:-"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int layer=0;layer<n/2;layer++)//Swap Layer by Layer
    {
        for(int j=layer;j<n-layer-1;j++)//leave last element of each layer
        {
            int temp=a[layer][j];
            a[layer][j]=a[n-j-1][layer];
            a[n-j-1][layer]=a[n-layer-1][n-j-1];
            a[n-layer-1][n-j-1]=a[j][n-layer-1];
            a[j][n-layer-1]=temp;
        }
    }
    cout<<"Rotated Matrix:-"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


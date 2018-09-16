#include<bits/stdc++.h>
using namespace std;
void shuffle(int a[],int n)
{
    int mid=n/2;
    for(int i=1;i<mid;i++)//n/2-1 passes are needed
    {
        // in 1st pass swap 1 middle pair
        // in 2nd pass swap 2 middle pair
        // in 3rd pass swap 3 middle pair
        for(int j=mid-i;j<mid+i;j+=2)// at ith pass swap i pairs
        {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        cout<<"Pass"<<i<<endl;
        for(int x=0;x<n;x++)
            cout<<a[x]<<" ";
        cout<<endl;
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
    shuffle(a,n);
    cout<<"ReShuffle Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
/*
First swap elements in the middle pair
Next swap elements in the middle two pairs
Next swap elements in the middle three pairs
iterate n-1 steps.

Ex: with n = 4.
a1 a2 a3 a4 b1 b2 b3 b4
a1 a2 a3 b1 a4 b2 b3 b4
a1 a2 b1 a3 b2 a4 b3 b4
a1 b1 a2 b2 a3 b3 a4 b4

T(n)=O(n*n)
pass1=1 swap
pass2=2 swap
.
.
passn/2=n/2 swap
b/c swap operation is O(1)
Total no of swaps=O(n*n)
T(n)=O(n*n);
*/

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
    int max=-9999999,x=-1,y=-1;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(max<sum)
            {
                max=sum;
                x=i;
                y=j;
            }
        }
    }
    cout<<"Maximum Sum SubArray="<<max<<endl;
    cout<<"Position(i,j)="<<x<<" "<<y;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter Number of Negations:-"<<endl;
    int k;
    cin>>k;
    int max_sum=0;
    while(k--)//For Each Pass
    {
        int min=a[0],minpos=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<min)
            {
                min=a[i];
                minpos=i;
            }
        }
        a[minpos]=-a[minpos];
    }
    for(int i=0;i<n;i++)
        max_sum+=a[i];
    cout<<"Max Sum After k Negations="<<max_sum<<endl;
    return 0;
}

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
    sort(a,a+n);
    int pos=0;
    while(a[pos]<0)
        pos++;
    int p=0;
    while(p<pos && k--)//For Each Pass
    {
        a[p]=-a[p];
        p++;
    }
    if(k!=0)//Still some pass are left
    {
        if(a[pos]==0)//Negate Zero Only so there is no change in the result
            k=0;
        else
        {
            //Find minimum element among the array b/c whole elements are +ve
            int min=a[0],minpos=0;
            for(int i=1;i<n;i++)
            {
              if(a[i]<min)
              {
                  min=a[i];
                  minpos=i;
              }
            }
            if(k%2!=0)//Odd negations are left when applied to the smallest element it will negate change that element
                a[minpos]=-a[minpos];
        }
    }
    for(int i=0;i<n;i++)
        max_sum+=a[i];
    cout<<"Max Sum After k Negations="<<max_sum<<endl;
    return 0;
}


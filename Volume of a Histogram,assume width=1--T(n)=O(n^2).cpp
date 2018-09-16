#include<bits/stdc++.h>
using namespace std;
int computevol(int a[],int low,int high)
{
    if(low>=high)
        return 0;
    int max=a[low],maxi=low;
    for(int i=low+1;i<=high;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            maxi=i;
        }
    }
    //Now maxi is pointing to longest bar that will divide
    int leftvol=0;
    int maxleft=a[low],maxlefti=low;
    for(int i=low;i<maxi;i++)
    {
        if(maxleft<a[i])
        {
            maxleft=a[i];
            maxlefti=i;
        }
    }
    for(int i=maxlefti+1;i<maxi;i++)
        leftvol+=(a[maxlefti]-a[i]);
    //Compute Right Portion
    int rightvol=0;
    int maxright=a[high],maxrighti=high;
    for(int i=high;i>maxi;i--)
    {
        if(maxright<a[i])
        {
            maxright=a[i];
            maxrighti=i;
        }
    }
    for(int i=maxi+1;i<maxrighti;i++)
        rightvol+=(a[maxrighti]-a[i]);
    return leftvol+rightvol+computevol(a,low,maxlefti)+computevol(a,maxrighti,high);
}
int main()
{
    int n;
    cout<<"Enter the No. of bars of histogram:-"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the Size of the Histogram Bars:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Volume="<<computevol(a,0,n-1);
    return 0;
}


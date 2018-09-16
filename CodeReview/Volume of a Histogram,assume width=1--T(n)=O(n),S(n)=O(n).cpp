#include<bits/stdc++.h>
using namespace std;
int computevol(int a[],int low,int high,int leftmax[],int rightmax[],int flag)
{
    if(low>=high)
        return 0;
    int rightvol=0,leftvol=0,maxi,maxlefti,maxrighti;
    if(flag==1)
    {
        maxi=leftmax[high-1];
        maxlefti=leftmax[maxi-1];
        for(int i=maxlefti+1;i<maxi;i++)
            leftvol+=(a[maxlefti]-a[i]);
        maxrighti=leftmax[high];
        for(int i=maxi+1;i<maxrighti;i++)
            rightvol+=(a[maxrighti]-a[i]);
    }
    else
    {
        maxi=rightmax[low+1];
        maxlefti=rightmax[low];
        for(int i=maxlefti+1;i<maxi;i++)
            leftvol+=(a[maxlefti]-a[i]);
        maxrighti=rightmax[maxi+1];
        for(int i=maxi+1;i<maxrighti;i++)
            rightvol+=(a[maxrighti]-a[i]);

    }
    /*int maxi;
    if(flag==1)//use leftmax
        maxi=leftmax[high-1];
    else
        maxi=rightmax[low+1];
    //Now maxi is pointing to longest bar
    //To compute 2nd max bar in left portion use left-max array
    int leftvol=0;
    int maxlefti=leftmax[maxi-1];
    for(int i=maxlefti+1;i<maxi;i++)
        leftvol+=(a[maxlefti]-a[i]);
    //To Compute 2nd max bar in Right Portion use Right-max Array
    int rightvol=0;
    int maxrighti=rightmax[maxi+1];
    for(int i=maxi+1;i<maxrighti;i++)
        rightvol+=(a[maxrighti]-a[i]);*/
    return leftvol+rightvol+computevol(a,low,maxlefti,leftmax,rightmax,1)+computevol(a,maxrighti,high,leftmax,rightmax,0);
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
    int leftmax[n],rightmax[n];
    leftmax[0]=0;rightmax[n-1]=n-1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[leftmax[i-1]])
            leftmax[i]=i;
        else
            leftmax[i]=leftmax[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[rightmax[i+1]])
            rightmax[i]=i;
        else
            rightmax[i]=rightmax[i+1];
    }
    cout<<"Volume="<<computevol(a,0,n-1,leftmax,rightmax,1);//1=leftmax && 0=rightmax
    return 0;
}
//0 0 4 0 0 6 0 0 3 0 8 0 0 2 0 5 2 0 3 0 0


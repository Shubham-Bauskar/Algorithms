#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
void binarysearch(int a[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            cout<<"Found at Index="<<mid<<endl;
            return;
        }
        if(a[mid]<key)
            low=mid+1;
        if(a[mid]>key)
            high=mid-1;
    }
    cout<<"Key Not Found"<<endl;
}
int main()
{
    printf("Enter the no. of Elements in Array\n");
    int n;
    scanf("%d",&n);
    printf("Enter the Elements in Array\n");
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the Key:-\n");
    int key;
    cin>>key;
    binarysearch(arr,0,n-1,key);
    return 0;
}

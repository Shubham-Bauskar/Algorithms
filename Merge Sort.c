#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,b[high-low+1],k=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i];
            i++;
        }
        if(a[i]>a[j])
        {
            b[k++]=a[j];
            j++;
        }
        if(a[i]==a[j])
        {
            b[k++]=a[i];
            j++;
        }
    }
    if(i>mid) // First Sub Array Finishes.
    {
        while(j<=high)
        {
            b[k++]=a[j];
            j++;
        }
    }
    if(j>high) // Second Sub Array Finishes.
    {
        while(i<=mid)
        {
            b[k++]=a[i];
            i++;
        }
    }
    int x,y;
    for(x=low,y=0;x<=high && y<k;x++,y++) //Copying Back Temporary Array to Main Array
        a[x]=b[y];
}
void mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
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
    printf("Sorted Array:-\n");
    mergesort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}

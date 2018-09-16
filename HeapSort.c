#include<stdio.h>
void max_heapify(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int large=i;
    if(l<n && arr[l]>arr[large])
        large=l;
    if(r<n && arr[r]>arr[large])
        large=r;
    if(large!=i && large<n)
    {
        int t=arr[i];
        arr[i]=arr[large];
        arr[large]=t;
        max_heapify(arr,n,large);
    }
}
void build_maxheap(int arr[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
        max_heapify(arr,n,i);
};
void heapsort (int arr[],int n)
{
    build_maxheap(arr,n);
    int i;
    for(i=0;i<n-1;i++)
    {
        int t=arr[0];
        arr[0]=arr[n-i-1];
        arr[n-i-1]=t;
        max_heapify(arr,n-i-1,0);
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
    heapsort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}

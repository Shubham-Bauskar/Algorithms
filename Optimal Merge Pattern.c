#include<stdio.h>
void min_heapify(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int large=i;
    if(l<n && arr[l]<arr[large])
        large=l;
    if(r<n && arr[r]<arr[large])
        large=r;
    if(large!=i && large<n)
    {
        int t=arr[i];
        arr[i]=arr[large];
        arr[large]=t;
        min_heapify(arr,n,large);
    }
}
void build_minheap(int arr[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
        min_heapify(arr,n,i);
};
void heapsort (int arr[],int n)
{
    build_minheap(arr,n);
    int i;
    for(i=0;i<n-1;i++)
    {
        int t=arr[0];
        arr[0]=arr[n-i-1];
        arr[n-i-1]=t;
        min_heapify(arr,n-i-1,0);
    }
}
int delete_max(int arr[],int n)
{
    int t=arr[n];
    arr[n]=arr[0];
    arr[0]=t;

}
int main()
{
    printf("Enter Number of Files:-\n");
    int n;
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter the Size of each File:-\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    heapsort(arr,n);
    cost+=delete_max(arr,n-1);
    cost+=delete_max(arr,n-2);
    insert(arr,cost,n-2);
}

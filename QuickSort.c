#include<stdio.h>
int partition(int a[],int low,int high)
{
    int left=low,right=high;
    int loc=low;
    while(1)
    {
        while(a[loc]<=a[right] && right!=loc)
            right--;
        if(loc==right)
            break;
        else
        {
            int temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        while(a[loc]>=a[left] && left!=loc)
            left++;
        if(loc==left)
            break;
        else
        {
            int temp=a[loc];
            a[loc]=a[left];
            a[left]=temp;
            loc=left;
        }
    }
    return loc;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
      int mid=partition(arr,low,high);
      quicksort(arr,low,mid-1);
      quicksort(arr,mid+1,high);
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
    quicksort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}

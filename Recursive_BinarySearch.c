#include<stdio.h>
int recursive_binary(int arr[],int low,int high,int key)
{
    if(low>high) // NO SubArray Exits
        return -1;
    int mid=(low+high)/2;
    if(key<arr[mid])
        high=mid-1;
    if(key>arr[mid])
        low=mid+1;
    if(key==arr[mid])
        return mid;
    return(recursive_binary(arr,low,high,key));
}
int main()
{
	printf("Enter the number of elements in an Array\n");
    int n;
    scanf("%d",&n);
    int arr[n],i,flag=0,key;
	printf("Enter Elements in an Array\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the key to be Search:-\n");
		scanf("%d",&key);
    flag=recursive_binary(arr,0,n-1,key);
    if(flag!=-1)
        printf("Key found at Index=%d\n",flag);
    else
        printf("Key not FOUND\n");
}

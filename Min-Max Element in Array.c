#include<stdio.h>
int main()
{
    printf("Enter the no. of Elements in Array\n");
    int n;
    scanf("%d",&n);
    printf("Enter the Elements in Array\n");
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int max=arr[0],min=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]<min)
            min=arr[i];
        if(arr[i]>max)
            max=arr[i];
    }
    printf("Max=%d Min=%d",max,min);
    return 0;
}

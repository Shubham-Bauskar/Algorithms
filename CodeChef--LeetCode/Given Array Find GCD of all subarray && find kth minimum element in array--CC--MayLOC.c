#include<stdio.h>
#include<stdlib.h>
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
int gcd(int k,int m)
{
    if(k<m)
    {
        int temp=k;
        k=m;
        m=temp;
    }
    while(m!=0)
    {
        int r=k%m;
        k=m;
        m=r;
    }
    return k;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int *a=(int *)malloc(n*sizeof(int));
    int i,j,x=0,gc;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int k=n*(n+1)/2;
    int *g=(int *)malloc(k*sizeof(int));
    for(k=1;k<=n;k++) // K denotes the size of substring
    {
       for(i=0;i<=n-k;i++)
       {
           gc=a[i];
           for(j=i+1;j<=i+k-1;j++)
           {
               gc=gcd(a[j],gc);
           }
           g[x++]=gc;
       }
    }
    quicksort(g,0,x-1);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",g[x-1]);
    }
}

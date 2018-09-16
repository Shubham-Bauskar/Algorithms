#include<stdio.h>
int main()
{
    printf("Enter the Number of Elements:-\n");
    int n;
    scanf("%d",&n);
    int a[n],i,j;
    printf("Enter the Values:-\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int flag=0;
    for(i=0,j=n-1;i<=n/2 && j>=n/2;)
    {
        if(a[i]>=0)
        {
            i++;
            continue;
        }
        if(a[j]<0)
        {
            j--;
            continue;
        }
        if(a[i]<0 && flag==0)
            flag=1;
        if(a[i]<0 && flag==1)
        {
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
            j--;
            flag=0;
        }
        if(a[j]>=0 && flag==0)
            flag=1;
        if(a[j]>=0 && flag==1)
        {
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
            j--;
            flag=0;
        }
    }
    printf("After Partition:-\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
/*
partition(first_iterator,last_iterator,condition_function);
C++ in built Function for partition
#include<algorithm>
bool fun(int x)
{
    return x>=0;
}
int main()
{
    int a[]={2,1,15,6,8,7};
    vector<int> v(a,a+6);
    partition(v.begin(),v.end(),fun);
    vector<int>::iterator p;
    for(p=v.begin();p!=v.end();p++)
        cout<<*p<<" ";
    return 0;
}
stable_partition(v.begin(),v.end(),fun);
*/

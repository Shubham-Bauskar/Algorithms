#include<stdio.h>
int main()
{
    int a[500],i;
    for(i=0;i<500;i++)
        a[i]=0;
    printf("Enter the Value of n:-\n");
    int n;
    scanf("%d",&n);
    a[0]=0;
    a[1]=2;
    a[2]=7;
    int x=2,j;
    for(i=7;i<=n;i++)
    {
        int carry=0,p=0;
        for(j=0;j<=x;j++)
        {
            p=a[j]*i+carry;
            carry=p/10;
            p=p%10;
            a[j]=p;
        }
        while(carry!=0)
        {
            a[++x]=carry%10;
            carry=carry/10;
        }
    }
    printf("%d-Factorial:-\n",n);
    for(i=x;i>=0;i--)
        printf("%d",a[i]);
    return 0;
}

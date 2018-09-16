#include<stdio.h>
int main()
{
    float n;
    scanf("%f",&n);
    int a[33],i,x;
    a[0]=0;
    for(i=1;i<=32;i++)
    {
        n=n*2;
        if(n>=1)
        {
            a[i]=1;
            n--;
        }
        else
            a[i]=0;
    }
    printf("%d.",a[0]);
    for(i=1;i<=32;i++)
        printf("%d",a[i]);
    return 0;
}

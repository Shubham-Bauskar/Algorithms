#include<stdio.h>
int isprime(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned int m,n,i;
        scanf("%u%u",&m,&n);
        for(i=m;i<=n;i++)
        {
            if(isprime(i)==1)
                printf("%d\n",i);
        }
    }
    return 0;
}

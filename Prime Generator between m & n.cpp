#include<stdio.h>
int isprime(int x)
{
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
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
        int n,m;
        scanf("%d%d",&m,&n);
        unsigned int i;
        for(i=m;i<=n;i++)
        {
            if(isprime(i)==1)
                printf("%d\n",i);
        }
        printf("\n");
    }
    return 0;
}

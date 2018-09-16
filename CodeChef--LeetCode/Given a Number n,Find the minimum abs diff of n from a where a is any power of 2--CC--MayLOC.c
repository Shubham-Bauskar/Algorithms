#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int n,k1=2,k2=2;
        scanf("%llu",&n);
        if(n==1)
            printf("0\n");
        if(n>=2)
        {
            while(k1<=n/2)
                k1=k1<<1;
            k2=k1<<1;
            if(n-k1<=k2-n)
                printf("%llu\n",n-k1);
            else
                printf("%llu\n",k2-n);
        }
    }
    return 0;
}

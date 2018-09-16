#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        unsigned int c=0;
        for(int i=5;i<=n;i=5*i)
            c+=n/i;
        printf("%u\n",c);
    }
    return 0;
}


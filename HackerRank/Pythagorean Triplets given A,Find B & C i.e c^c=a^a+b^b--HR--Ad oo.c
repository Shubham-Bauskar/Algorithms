#include<stdio.h>
int main()
{
    unsigned int a;
    scanf("%d",&a);
    unsigned int m=0,n=0,i,j;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=a;j++)
        {
            if(2*i*j==a)
            {
                m=i;
                n=j;
                printf("%u %u %u\n",a,abs(m*m-n*n),m*m+n*n);
                goto end;
            }
        }
    }
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=a;j++)
        {
            if(abs((i+j)*(i-j))==a)
            {
                m=i;
                n=j;
                printf("%u %u %u\n",a,2*m*n,m*m+n*n);
                goto end;
            }
        }
    }
    end :
      return 0;
}

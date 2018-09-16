#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i;
        scanf("%d%d",&n,&k);
        int *a=(int *)malloc((n+1)*sizeof(int));
        int *st=(int *)malloc((n+1)*sizeof(int));
        for(i=1;i<=n;i++)
            st[i]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==i)
                st[i]=-1;
            else
            {
               if(st[a[i]]!=-1)
                    st[a[i]]++;
            }
        }
        unsigned int count=0;
        for(i=1;i<=n;i++)
        {
            if(st[i]>=k)
                count++;
        }
        printf("%u\n",count);
    }
    return 0;
}

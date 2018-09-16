#include<stdio.h>
int main()
{
    int s;
    scanf("%d",&s);
    while(s--)
    {
        int n;
        scanf("%d",&n);
        int a[n],i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int flag=1;
        if(a[0]!=1)
            flag=0;
        else if(n%2==0)
            flag=0;
        else
        {
            int j=n/2;
            for(i=0;i<j;i++)
            {
                if(a[i+1]-a[i]!=1)
                {
                    flag=0;
                    break;
                }
            }
            for(i=j;i<n-1;i++)
            {
                if(a[i+1]-a[i]!=-1)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

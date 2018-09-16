#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r;
    scanf("%d",&r);
    while(r--)
    {
        int l;
        scanf("%d",&l);
		l+=10;
        char *a=(char *)malloc((l)*sizeof(char));
		l-=10;
        scanf("%s",a);
        int flag=1,i,j;
        int h=0,t=0;
        for(i=0;i<l;i++)
        {
            if(a[i]=='T')
            {
                flag=0;
                goto result;
            }
            if(a[i]=='H')
                break;
        }
        for(i=0;i<l;i++)
        {
            if(a[i]=='H')
                h++;
            if(a[i]=='T')
                t++;
            if(a[i]=='H')
            {
                for(j=i+1;j<l;j++)
                {
                    if(a[j]=='H')
                    {
                        flag=0;
                        goto result;
                    }
                    if(a[j]=='T')
                        break;
                }
            }
            if(a[i]=='T')
            {
                for(j=i+1;j<l;j++)
                {
                    if(a[j]=='T')
                    {
                        flag=0;
                        goto result;
                    }
                    if(a[j]=='H')
                        break;
                }
            }
        }
        if(h!=t)
            flag=0;
        result:
        if(flag==1)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}

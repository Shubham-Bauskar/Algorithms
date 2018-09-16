#include<stdio.h>
int main()
{
    printf("Enter String A:-\n");
    char *a=(char *)malloc(1000*sizeof(char));
    scanf("%s",a);
    printf("Enter String B:-\n");
    char *b=(char *)malloc(1000*sizeof(char));
    scanf("%s",b);
    int al=strlen(a);
    int bl=strlen(b);
    int i,j;
    if(al!=bl)
        printf("--NO\n");
    else
    {
        int st[al];
        for(i=0;i<al;i++)
            st[i]=0;
        for(i=0;i<bl;i++)
        {
           for(j=0;j<al;j++)
           {
               if(b[i]==a[j] && st[j]==0)
               {
                   st[j]=1;
                   break;
               }
           }
        }
        int flag=1;
        for(i=0;i<al;i++)
        {
            if(st[i]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            printf("--YES\n");
        else
            printf("--NO\n");
    }
    return 0;
}

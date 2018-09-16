#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isSubString(char t[],char b[])
{count++;
    int k=strlen(t),i;
    for(i=0;i<k;i++)
    {
        if(t[i]!=b[i])
            return 0;
    }
    return 1;
}
int main()
{
    printf("Enter 2 Strings a & b:-\n");
    char *a=(char *)malloc(1000*sizeof(char));
    char *b=(char *)malloc(1000*sizeof(char));
    scanf("%s%s",a,b);
    int la=strlen(a),lb=strlen(b);
    if(la!=lb)
        printf("--NO\n");
    else
    {
        int flag=0,i,j;
        for(i=0;i<la-1;i++)//O(n)
        {
            char *t=(char *)malloc(1000*sizeof(char));
            int x=0;
            for(j=i+1;j<la;j++)//O(n) overall=O(n*n)
                t[x++]=a[j];
            for(j=0;j<=i;j++)
                t[x++]=a[j];
            t[x]='\0';
            if(t[0]==b[0])
            {
                if(isSubString(t,b)==1) //O(n) overall=O(n*n)
                {
                   printf("--YES\n");
                   flag=1;
                   break;
                }
            }
        }
        if(flag==0)
            printf("--NO\n");
    }
    return 0;
}


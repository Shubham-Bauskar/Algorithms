#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isSubString(char s1[],char s2[])
{
    int len=strlen(s1)-strlen(s2);
    int len2=strlen(s2);
    int i,j=0,k;
    char s3[10000];
    for(i=0;i<=len;i++)
    {
        if(s1[i]==s2[j])
        {
            for(k=0;k<len2;k++)
                s3[k]=s1[k+i];
            s3[k]='\0';
            if(strcmp(s3,s2)==0)
                return 1;
        }
    }
    return 0;
}
int main()
{
    printf("Enter 2 Strings a & b:-\n");
    char *a=(char *)malloc(1000*sizeof(char));
    char *b=(char *)malloc(1000*sizeof(char));
    scanf("%s%s",a,b);
    char *c=(char *)malloc(1000*sizeof(char));
    strcpy(c,b);
    strcat(c,b);
    if(isSubString(c,a)==1)
        printf("--YES\n");
    else
        printf("--NO\n");
    return 0;
}



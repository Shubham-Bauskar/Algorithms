#include<stdio.h>
int main()
{
    printf("Enter Unsorted String:-\n");
    char *s=(char *)malloc(1000*sizeof(char));
    scanf("%s",s);
    int ch[27],i;
    for(i=0;i<27;i++)
        ch[i]=0;
    int k=strlen(s),x=0;
    for(i=0;i<k;i++)
    {
        int sm=s[i]-96;
        ch[sm]++;
    }
    for(i=1;i<=26;i++)
    {
        int m=ch[i];
        while(m--)
            s[x++]=96+i;
    }
    printf("Sorted Array:-\n");
    printf("%s\n",s);
    return 0;
}

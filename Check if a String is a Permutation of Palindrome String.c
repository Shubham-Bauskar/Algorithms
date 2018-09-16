#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    printf("Enter the String:-\n");
    char *a=(char *)malloc(1000*sizeof(char));
    scanf("%s",a);
    int st[27],i,k=strlen(a);
    for(i=0;i<=26;i++)
        st[i]=0;
    for(i=0;i<k;i++)
        st[a[i]-96]++;
    int flag=0;
    for(i=1;i<=26;i++)
    {
        if(st[i]%2!=0)
            flag++;
    }
    if(flag<=1)
        printf("--YES\n");
    else
        printf("--NO\n");
    return 0;
}

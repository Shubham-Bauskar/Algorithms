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
        int sta[27],stb[27];
        for(i=0;i<27;i++)
            sta[i]=stb[i]=0;
        for(i=0;i<al;i++)
        {
            sta[a[i]-96]++;
            stb[b[i]-96]++;
        }
        for(i=1;i<=26;i++)
        {
            if(sta[i]!=stb[i])
                break;
        }
        if(i>26)
            printf("--YES\n");
        else
            printf("--NO\n");
    }
    return 0;
}

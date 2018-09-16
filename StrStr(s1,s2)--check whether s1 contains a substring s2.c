int main()
{
    char *s1=0,*s2=0;
    s1=(char *)malloc(1000000);
    printf("Enter the String S1 i.e strstr(s1,s2):-\n");
    gets(s1);
    printf("Enter the String S2 i.e strstr(s1,s2):-\n");
    s2=(char *)malloc(10000);
    gets(s2);
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
            {
                printf("SUBSTRING FOUND AT INDEX %d",i);
                break;
            }
        }
    }
    return 0;
}

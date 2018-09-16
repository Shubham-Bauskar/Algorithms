#include<stdio.h>
#include<string.h>
int main()
{
    char *s=(char *)malloc(100001*sizeof(char));
    scanf("%s",s);
    int k=strlen(s);
    int count=0;
    int j=k-1;
    while(j!=0)
    {
        while(s[j]!='1')
            j--;
        int  i=j;
        while(i>=0)
        {
            if(s[i]=='0')
                s[i]='1';
            else
                s[i]='0';
            i--;
        }
        count++;
    }
    printf("%d\n",count);
    return 0;
}

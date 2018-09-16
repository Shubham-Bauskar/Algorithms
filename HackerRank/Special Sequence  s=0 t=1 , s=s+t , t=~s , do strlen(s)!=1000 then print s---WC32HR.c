#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000],t[10000];
    int i;
    s[0]='0';t[0]='1';s[1]='\0';t[1]='\0';
    while(strlen(s)<=1000)
    {
        strcat(s,t);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='0')
                t[i]='1';
            else
                t[i]='0';
         }
         t[i]='\0';
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        printf("%c\n",s[x]);
    }
    return 0;
}


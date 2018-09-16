#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ispalindrome(char a[],int k)
{
    int i;
    for(i=0;i<k/2;i++)
    {
        if(a[i]!=a[k-1-i])
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char *a=(char *)malloc(12500*sizeof(char));
        scanf("%s",a);
        int k=strlen(a),i;
        for(i=0;i<k/2;i++)
        {
            if(a[i]=='.' && a[k-1-i]!='.')
                a[i]=a[k-1-i];
            else if(a[k-1-i]=='.' && a[i]!='.')
                a[k-1-i]=a[i];
            else if(a[k-i-1]=='.' && a[i]=='.')
                a[i]=a[k-i-1]='a';
        }
        if(k%2!=0 && a[k/2]=='.')
                a[k/2]='a';
        if(ispalindrome(a,k)==1)
            printf("%s\n",a);
        else
            printf("-1\n");
    }
    return 0;
}

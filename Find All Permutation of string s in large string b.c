#include<stdio.h>
#include<string.h>
int ispermute(char b[],int low,int high,char s[],int s1)
{
    // Time Complexity = O(s*s)
    int st[s1],i,j;
    for(i=0;i<s1;i++)
        st[i]=0;
    for(i=low;i<=high;i++) // This loop iterates O(s*s) times where s is length of permute string
    {
        for(j=0;j<s1;j++)
        {
            if(b[i]==s[j] && st[j]==0)
            {
                st[j]=1;
                break;
            }
        }
    }
    int flag=1;
    for(i=0;i<s1;i++)
    {
        if(st[i]==0)
            return 0;
    }
    return 1;
}
int main()
{
    printf("Enter String S:-\n");
    char *s=(char *)malloc(10*sizeof(char));
    scanf("%s",s);
    printf("Enter String B:-\n");
    char *b=(char *)malloc(1000*sizeof(char));
    scanf("%s",b);
    int sl=strlen(s);
    int bl=strlen(b);
    int i,k;
    printf("Index at Which Permutation Occurs in String B:-\n");
    for(i=0;i<=bl-sl;i++) // This loop iterates (b-s) times where b=length of main string & s=length of permute string
    {
        if(ispermute(b,i,i+sl-1,s,sl)==1)
        {
             printf("Index=%d ",i);
             for(k=i;k<=i+sl-1;k++)
                printf("%c",b[k]);
             printf("\n");
        }
    }
    return 0;
    // Time Complexity=(b-s)*(s*s)==bs^2-s^3;
}

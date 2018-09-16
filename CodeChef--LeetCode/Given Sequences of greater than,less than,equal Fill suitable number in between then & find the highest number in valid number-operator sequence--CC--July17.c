#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int longest_sequence_lessthan(char a[])
{
    int k=strlen(a);
    int max=0,temp=0,i;
    for(i=0;i<k;i++)
    {
        if(a[i]=='<')
            temp++;
        if(a[i]=='>')
        {
            if(max<temp)
                max=temp;
            temp=0;
        }
    }
    if(max<=temp)
      max=temp;
    return max;
}
int longest_sequence_greaterthan(char a[])
{
    int k=strlen(a);
    int max=0,temp=0,i;
    for(i=0;i<k;i++)
    {
        if(a[i]=='>')
            temp++;
        if(a[i]=='<')
        {
            if(max<temp)
                max=temp;
            temp=0;
        }
    }
    if(max<=temp)
        max=temp;
    return max;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       char *a=(char *)malloc(1050*sizeof(char));
       scanf("%s",a);
       int k=strlen(a),i;
       int less=0,greater=0;
       less=longest_sequence_lessthan(a);
       greater=longest_sequence_greaterthan(a);
       printf("less=%d greater=%d\n",less,greater);
       if(less<=greater)
          printf("---%d\n",greater+1);
       else
          printf("---%d\n",less+1);
    }
    return 0;
}

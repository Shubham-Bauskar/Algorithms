#include<stdio.h>
#include<string.h>
int longest_sequence_ones(char a[])
{
    int k=strlen(a);
    int max=0,temp=0,i;
    for(i=0;i<k;i++)
    {
        if(a[i]=='1')
            temp++;
        if(a[i]=='0')
        {
            if(max<temp)
                max=temp;
            temp=0;
        }
    }
    return max;
}
int main()
{
    printf("Enter the String of 0s-1s:-\n");
    char *a=(char *)malloc(100*sizeof(char));
    scanf("%s",a);
    printf("Longest Sequence of 1s=%d",longest_sequence_ones(a));
    return 0;
}

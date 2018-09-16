#include<stdio.h>
int main()
{
    char *a=(char *)malloc(100*sizeof(char));
    scanf("%s",a);
    printf("\nLength of String=%d",printf("%s",a));
    return 0;
}

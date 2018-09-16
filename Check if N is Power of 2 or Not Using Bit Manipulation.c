#include<stdio.h>
int main()
{
    printf("Enter the Number:-\n");
    int n;
    scanf("%d",&n);
    if((n&(n-1))==0)
        printf("N is Power of 2");
    else
        printf("N is Not a Power of 2");
    return 0;
}

// Mask will be of form 0000001111 ie 0s followed by i 1s.
#include<stdio.h>
void printbin(int n)
{
    int a[100],x=0,i;
    while(n!=0)
    {
        if(n%2==0)
            a[x++]=0;
        else
            a[x++]=1;
        n=n/2;
    }
    for(i=x-1;i>=0;i--)
        printf("%d",a[i]);
}
int main()
{
    printf("Enter the Number:-\n");
    int n;
    scanf("%d",&n);
    printf("Binary Representation of Number=");
    printbin(n);
    printf("\nEnter the Index i(inclusive):-\n");
    int i;
    scanf("%d",&i);
    int ans=pow(2,i)-1;//pow(2,i) is = 1<<i;
    printf("MASK=");
    printbin(ans);
    n=n&ans;
    printf("\nNew Number Cleared upto msd->i = ");
    printbin(n);
    return 0;
}

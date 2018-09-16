// First Clear the bit in b/w [i,j].
// Then m<<i and take its OR product.
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
    printf("\n");
}
int no_of_bits(int n)
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
    return x;
}
int main()
{
    printf("Enter the Number N and M:-\n");
    int n,m;
    scanf("%d%d",&n,&m);
    printbin(n);
    printbin(m);
    printf("Binary Representation of N=");
    printbin(n);
    printf("Binary Representation of M=");
    printbin(m);
    printf("Enter the Index i,j at which u want to insert:-\n");
    int i,j;
    scanf("%d%d",&i,&j);
    // Clearing Bits b/w i & j
    int mask=pow(2,no_of_bits(m))-1;
    m=m<<i;
    mask=mask<<i;
    printf("Mask=%d Mask-Bin=",mask);
    printbin(mask);
    n=n&(~mask);
    printf("Cleared bit b/w [i,j]=");
    printbin(n);
    // Merging M into N
    n=n|m;
    printf("Inserted M into N=");
    printbin(n);
    return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;
void printbin(int n,int a[])
{
    int x=31,i;
    while(n!=0)
    {
        if(n%2==0)
            a[x--]=0;
        else
            a[x--]=1;
        n=n/2;
    }
    while(x>=0)
    {
        a[x]=0;
        x--;
    }
    for(i=0;i<=31;i++)
        printf("%d",a[i]);
    printf("\n");
}
int convert(int a[],int b[])
{
    int bitflipped=0;
    for(int j=31;j>=0;j--)
    {
        if(b[j]!=a[j])
            bitflipped++;
    }
    return bitflipped;
}
int main()
{
    printf("Enter the Number:-\n");
    int n,m,a[32],b[32];
    scanf("%d",&n);
    printf("Binary Representation=");
    printbin(n,a);
    scanf("%d",&m);
    printf("Binary Representation=");
    printbin(m,b);
    int nobitsflipped=convert(a,b);
    printf("No of Bits Flipped=%d\n",nobitsflipped);
    return 0;
}
// Find The Number of 1s in Binary Representation of A^B

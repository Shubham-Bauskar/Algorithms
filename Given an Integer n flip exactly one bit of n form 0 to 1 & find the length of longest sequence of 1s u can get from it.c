#include<stdio.h>
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
int if_flip_ith_bit(int a[],int i)
{
    a[i]=1;
    int max=0,temp=0,j;
    for(j=0;j<32;j++)
    {
        if(a[j]==1)
            temp++;
        if(a[j]==0)
        {
            if(max<temp)
                max=temp;
            temp=0;
        }
    }
    a[i]=0;
    return max;
}
int binary_integer(int a[])
{
    int max=0,i;
    for(i=31;i>=0;i--)
    {
        if(a[i]==1)
            max+=1<<31-i;//max+=pow(2,31-i);
    }
    return max;
}
int main()
{
    printf("Enter the Number:-\n");
    int n,a[32];
    scanf("%d",&n);
    printf("Binary Representation=");
    printbin(n,a);
    int max=0,bitflipped=-1,temp,i;
    for(i=0;i<=31;i++)
    {
        if(a[i]==0)
        {
            temp=if_flip_ith_bit(a,i);
            if(temp>max)
            {
                max=temp;
                bitflipped=i;
            }
        }
    }
    a[bitflipped]=1;
    printf("Longest Sequence of 1s we can get=%d\nBit Flipped=%d\n",max,bitflipped);
    printf("New Number=%d\n",binary_integer(a));
    return 0;
}

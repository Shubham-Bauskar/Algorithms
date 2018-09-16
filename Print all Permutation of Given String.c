#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(char *p,char *q)
{
    char t=*p;
    *p=*q;
    *q=t;
}
int count=1;
void permute(char *a,int l,int r) // l=starting index r=ending index of substring which is to be permute
{
    if(l==r)
    {
        printf("(%d)%s\n",count,a);
        count++;
        return;
    }
    else
    {
        int i;
        for(i=l;i<=r;i++)
        {
            swap(a+l,a+i); // Fixing one character at a time
            permute(a,l+1,r); // Permuting the remaining character
            swap(a+l,a+i); // Getting back the original string which is fixed
        }
    }
}
int main()
{
    printf("Enter the String:-\n");
    char *a=(char *)malloc(1000000*sizeof(char));
    scanf("%s",a);
    printf("Permutations:-\n");
    permute(a,0,strlen(a)-1);
    return 0;
}

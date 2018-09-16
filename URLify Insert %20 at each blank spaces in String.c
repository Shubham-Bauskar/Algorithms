#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    printf("Enter the String:-\n");
    char *a=(char *)malloc(10000*sizeof(char));
    gets(a);
    int i;
    for(i=0;i<strlen(a);)
    {
        if(a[i]==32)
        {
            int j=strlen(a)-1;
            while(j!=i)
            {
                a[j+2]=a[j];
                j--;
            }
            a[i]='%';
            a[i+1]='2';
            a[i+2]='0';
            i=i+3;
            a[strlen(a)]='\0';
        }
        else
            i++;
    }
    printf("URL=%s",a);
    return 0;
}

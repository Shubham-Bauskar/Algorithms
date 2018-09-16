#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    printf("Enter the String:-\n");
    char *a=(char *)malloc(1000*sizeof(char));
    scanf("%s",a);
    int k=strlen(a),x=0,i;
    char *t=(char *)malloc(1000*sizeof(char));
    for(i=0;i<k;)
    {
        t[x++]=a[i];
        int count=1,j=i+1;
        while(a[j]==a[i])
        {
            count++;
            j++;
        }
        t[x++]=count+48;
        i=j;
    }
    t[x]='\0';
    if(strlen(a)>=strlen(t))
        printf("Compressed String=%s",t);
    else
        printf("Cannot be Compressed using this Method");
    return 0;
}

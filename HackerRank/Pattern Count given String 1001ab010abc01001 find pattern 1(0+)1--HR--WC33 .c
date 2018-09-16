#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char *a=(char *)malloc(2500*sizeof(char));
        scanf("%s",a);
        int k=strlen(a),count=0,i,j;
        for(i=0;i<=k-3;i++)
        {
            if(a[i]=='1' && a[i+1]!='1')
            {
                j=i+1;
                while(a[j]=='0')
                    j++;
                if(a[j]=='1')
                    count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

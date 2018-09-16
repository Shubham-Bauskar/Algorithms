#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,m,b,e,i;
        for(i=0;i<4;i++)
        {
            char s[11];
            scanf("%s",s);
            int x;
            scanf("%d",&x);
            if(strcmp(s,"Barcelona")==0)
                 b=x;
            if(strcmp(s,"Malaga")==0)
                 m=x;
            if(strcmp(s,"RealMadrid")==0)
                 r=x;
            if(strcmp(s,"Eibar")==0)
                 e=x;
        }
        if(m>r && b>e)
            printf("Barcelona\n");
        else
            printf("RealMadrid\n");
    }
    return 0;
}

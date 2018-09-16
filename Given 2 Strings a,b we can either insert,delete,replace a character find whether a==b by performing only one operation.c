#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    printf("Enter two Strings:-\n");
    char *a=(char *)malloc(1000*sizeof(char));
    char *b=(char *)malloc(1000*sizeof(char));
    scanf("%s%s",a,b);
    int sta[27],stb[27],i;
    for(i=0;i<=26;i++)
        sta[i]=stb[i]=0;
    int la=strlen(a),lb=strlen(b);
    for(i=0;i<la;i++)
        sta[a[i]-96]++;
    for(i=0;i<lb;i++)
        stb[b[i]-96]++;
    int del=0,rep=0,flagrepa=0,flagrepb=0,opt=0;
    for(i=1;i<=26;i++)
    {
        if(sta[i]>0 && stb[i]>0 && abs(sta[i]-stb[i])==1)//DElETION OPT
        {
            del++;
            opt++;
        }
        if(sta[i]==1 && stb[i]==0 && flagrepb==0)
            flagrepa=1;
        if(sta[i]==1 && stb[i]==0 && flagrepb==1)
        {
            opt++;
            rep++;
        }
        if(stb[i]==1 && sta[i]==0 && flagrepa==0)
            flagrepb=1;
        if(stb[i]==1 && sta[i]==0 && flagrepa==1)
        {
            opt++;
            rep++;
        }
        if(opt>1 || abs(sta[i]-stb[i])>1)
            break;
    }
    printf("del=%d,rep=%d",del,rep);
    if(opt<=1)
        printf("--YES\n");
    else
        printf("--NO\n");}
    return 0;
}

#include<stdio.h>
int main()
{
    printf("Enter the Number of Jobs\n");
    int n;
    scanf("%d",&n);
    int jb[n],v[n],d[n],i,in[n];
    printf("Enter Profit and Deadline of each Job:-\n");
    int max=-1;
    for(i=0;i<n;i++)
    {
        jb[i]=i;
        in[i]=0;
        scanf("%d%d",&v[i],&d[i]);
        if(max<d[i])
            max=d[i];
    }
    int maxprofit=0,j;
    for(i=0;i<n;i++) //REVERSE SORTING ON BASIS OF PROFIT
       for(j=i;j<n;j++)
       {
          if(v[j]<v[j+1]) //SWAP FOR REVERSE SORTING
          {
              int t=v[j];
              v[j]=v[j+1];
              v[j+1]=t;
              int t1=jb[j];
              jb[j]=jb[j+1];
              jb[j+1]=t1;
              int t2=d[j];
              d[j]=d[j+1];
              d[j+1]=t2;
          }
       }
    for(i=0;i<n;i++)
        printf("\n\n%d %d %d\n",jb[i],v[i],d[i]);
    int seq[max];
    for(i=0;i<max;i++)
        seq[i]=-1;
    for(i=0;i<max;i++)
    {
       int flag=0;
       if(seq[d[i]]==-1)
        {
            flag=1;
            seq[d[i]]=1;
        }
       else
       {
           for(j=d[i]-1;j>=0;j--)
           {
               if(seq[j]==-1)
               {
                   flag=1;
                   break;
               }
           }
       }
       if(j>=0)
        seq[j]=1;
       if(flag)
         {
             maxprofit+=v[i];
             in[jb[i]]=1;
         }
    }
    printf("MAX PROFIT=%d\n",maxprofit);
}

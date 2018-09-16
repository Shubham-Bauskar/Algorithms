#include<stdio.h>
int getMaxMonsters(int n,int hit,int t,int a[])
{
   int max=0,i;
   while(t!=0)
   {
      int min=a[0],mini=0;
      for(i=1;i<n;i++)
      {
          if(a[i]!=-1 && min>a[i])
          {
              min=a[i];
              mini=i;
          }
      }
      if(min<=hit)
      {
          a[mini]=-1;
          t--;
          max++;
      }
      if(min>hit)
      {
          int temp=0;
          if(min%hit==0)
              temp=min/hit;
          else
              temp=min/hit+1;
          if(temp<=t)
          {
              a[mini]=-1;
              max++;
              t-=temp;
          }
          else
              break;
      }
   }
   return max;
}
int main()
{
    int n,hit,t,i;
    scanf("%d%d%d",&n,&hit,&t);
    int *h=malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
       scanf("%d",&h[i]);
    int result = getMaxMonsters(n,hit,t,h);
    printf("%d\n", result);
    return 0;
}

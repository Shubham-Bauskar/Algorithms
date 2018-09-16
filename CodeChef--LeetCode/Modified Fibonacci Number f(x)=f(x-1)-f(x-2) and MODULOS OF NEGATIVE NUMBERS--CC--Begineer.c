#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      long curr,prev;
      int n;
      scanf("%ld%ld%d",&prev,&curr,&n);
      long next=0;
      while(n!=2)
      {
          next=curr-prev;
          prev=curr;
          curr=next;
          n--;
      }
      int mod;
      if(next<0)
        mod=(next%1000000007)+1000000007;
      else
        mod=next%1000000007;
      printf("%ld\n",mod);
    }
    return 0;
}

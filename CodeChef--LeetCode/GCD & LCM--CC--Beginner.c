#include<stdio.h>
int gcd(int a,int b)
{
  if(a<b)
  {
    int temp=a;
    a=b;
    b=temp;
  }
  if(b==0)
   return a;
  return (gcd(b,a%b));
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    int g=gcd(a,b);
    printf("%d %d\n",g,a*b/g);
  }
  return 0;
}
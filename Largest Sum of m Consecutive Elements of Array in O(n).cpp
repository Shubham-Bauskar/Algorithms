#include <iostream>
using namespace std;
int maxConsecutive(int *a,int n,int m)
{
  int sum=0;
  for(int i=0;i<m;i++)
    sum+=a[i];
  int max=sum;
  for(int i=m;i<n;i++)
  {
     sum=sum+a[i]-a[i-m];
     if(sum>max)
        max=sum;
  }
  return max;
}
int main()
{
    cout<<"Enter the Size of Array:-"<<endl;
    int n,m;
    cin>>n;
    cout<<"Enter the Value of 'm':-"<<endl;
    cin>>m;
    int a[n];
    cout<<"Enter the Elements in Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Largest Sum of m Consecutive Elements="<<maxConsecutive(a,n,m);
    return 0;
}

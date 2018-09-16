#include<iostream>
using namespace std;
int maxe(int a,int b)
{
    return a>=b?a:b;
}
int mine(int a,int b)
{
    return a>=b?b:a;
}
int getpos(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            return i;
    }
    return 0;
}
int getmedian(int a[],int low,int high)
{
    int mid=(high+low)/2;
    if((high-low+1)%2==0)
        return (a[mid]+a[mid+1])/2;
    return a[mid];
}
float median(int a[],int al,int ah,int b[],int bl,int bh,int n)
{
    if(al+1==ah && bl+1==bh)//When n==2
        return (maxe(a[al],b[bl])+mine(a[ah],b[bh]))/2.0;
    int m1=getmedian(a,al,ah);
    int posm1=getpos(a,n,m1);
    int m2=getmedian(b,bl,bh);
    int posm2=getpos(b,n,m2);
    if(m1==m2)
        return m1;
    if(m1<m2)//{all elements of A less than m1,some elements of B}m1{...}m2{all elements of B more than m2,some elements of A}
      return median(a,posm1,ah,b,bl,posm2,n);
    if(m1>m2)//{all elements of B less than m2,some elements of A}m2{...}m1{all elements of A more than m1,some elements of B}
      return median(a,al,posm1,b,posm2,bh,n);
}
int main()
{
    cout<<"Enter the Size of Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter Both the Arrays:-"<<endl;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<"MEDIAN="<<median(a,0,n-1,b,0,n-1,n);
    return 0;
}

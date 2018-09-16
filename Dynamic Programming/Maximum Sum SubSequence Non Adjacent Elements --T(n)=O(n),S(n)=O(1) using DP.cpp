#include<bits/stdc++.h>
using namespace std;
int max_sub_seq_non_adjacent(int a[],int n)
{
   int inc=a[0],exc=0;//Include First Element & Exclude it.
   for(int i=1;i<n;i++)
   {
       int temp=inc;
       inc=max(exc+a[i],inc);//Max(pick element a[i]+whatever done best by not picking a[i-1] i.e exc,don't pick a[i] & pick whatever best done by picking a[i-1])
       exc=temp;
   }
   return inc;
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Maximum Sum SubSequence Non Adjacent="<<max_sub_seq_non_adjacent(a,n);
    return 0;
}

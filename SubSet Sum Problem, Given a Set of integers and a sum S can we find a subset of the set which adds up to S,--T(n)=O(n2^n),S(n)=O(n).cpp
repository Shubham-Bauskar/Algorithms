#include<bits/stdc++.h>
using namespace std;
int found=0;
void subset_sum(int a[],int n,int b[],int sum,int i)
{
   if(i==n-1)//Marked the Last Element
   {
       int tsum=0;
       for(int j=0;j<n;j++)
       {
           if(b[j]==1)
            tsum+=a[j];
       }
       if(tsum==sum)
       {
           found=1;
           for(int j=0;j<n;j++)
           {
               if(b[j]==1)
                cout<<a[j]<<" ";
           }
           cout<<endl;
       }
       return;
   }
   b[i+1]=1;
   subset_sum(a,n,b,sum,i+1);
   b[i+1]=0;
   subset_sum(a,n,b,sum,i+1);
}
int main()
{
    cout<<"Enter the Number of Elements in the Set:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Set:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Sum:-"<<endl;
    int sum;
    cin>>sum;
    int b[n];
    b[0]=0;
    subset_sum(a,n,b,sum,0);
    b[0]=1;
    subset_sum(a,n,b,sum,0);
    if(found==0)
        cout<<"Set Not Found"<<endl;
    return 0;
}


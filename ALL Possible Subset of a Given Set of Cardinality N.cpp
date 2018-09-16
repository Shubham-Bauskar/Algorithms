#include<iostream>
#include<math.h>
using namespace std;
void findbin(int x,int b[],int n)
{
    int t=n;
    n--;
    while(x!=0)
    {
        if(x%2==0)
            b[n--]=0;
        else
            b[n--]=1;
        x=x/2;
    }
}
int main()
{
    cout<<"Enter the Cardinality of Set:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in Set:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k=pow(2,n),b[n];
    for(int i=0;i<n;i++)
        b[i]=0;
    cout<<"ALL POSSIBLE SUBSETS :-"<<endl;
    for(int i=0;i<k;i++)
    {
        findbin(i,b,n);
        cout<<"{ ";
        for(int j=0;j<n;j++)
        {
            if(b[j]==1)
                cout<<a[j]<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}

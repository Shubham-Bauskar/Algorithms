#include<iostream>
#include<math.h>
using namespace std;
void findbin(int a[],int n)
{
    int i=31;
    for(int j=0;j<=31;j++)
        a[j]=0;
    while(n!=0)
    {
        if(n%2==0)
            a[i--]=0;
        else
            a[i--]=1;
        n=n/2;
    }
}
int convert(int a[])
{
    int temp=0;
    for(int i=31;i>=0;i--)
        temp+=a[i]*pow(2,31-i);
    return temp;
}
int main()
{
    cout<<"Enter the Number"<<endl;
    int n;
    cin>>n;
    int a[32];
    cout<<"Binary Representation of Given Number = ";
    findbin(a,n);
    for(int i=0;i<=31;i++)
        cout<<a[i];
    cout<<endl;
    int small[32],large[32];
    for(int i=0;i<=31;i++)
        small[i]=large[i]=a[i];
    // Finding Next Largest
    cout<<"Binary Representation of next larger number having equal numbers of 1s = ";
    int i=31,j;
    // i will convert 1-->0
    // j will convert 0-->1
    // for next larger number location i (lower index) then j (higher index)
    while(large[i]==0)
        i--;
    j=i-1;
    while(large[j]==1)
        j--;
    int count_no_1=0;
    for(int x=j+1;x<i;x++)
    {
        if(large[x]==1)
            count_no_1++;
    }
    large[j]=1;
    large[i]=0;
    for(int x=j+1;x<=31;x++)
        large[x]=0;
    int x=31;
    while(count_no_1!=0)
    {
       large[x--]=1;
       count_no_1--;
    }
    for(int i=0;i<=31;i++)
        cout<<large[i];
    cout<<endl<<"Next Largest Number = ";
    cout<<convert(large)<<endl;
    // Finding Next Smallest
    cout<<"Binary Representation of next Smaller number having equal numbers of 1s = ";
    i=31;
    // i will convert 0-->1
    // j will convert 1-->0
    // for next larger number location i (lower index) then j (higher index)
    while(small[i]==1)
        i--;
    j=i-1;
    while(small[j]==0)
        j--;
    small[j]=0;
    small[i]=1;
    count_no_1=0;
    for(int x=j+1;x<32;x++)
    {
        if(small[x]==1)
            count_no_1++;
    }
    for(int x=j+1;x<=31;x++)
        small[x]=0;
    x=j+1;
    while(count_no_1!=0)
    {
       small[x++]=1;
       count_no_1--;
    }
    for(int i=0;i<=31;i++)
        cout<<small[i];
    cout<<endl<<"Next Smallest Number = ";
    cout<<convert(small)<<endl;
    return 0;
}

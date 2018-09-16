#include<bits/stdc++.h>
using namespace std;
void add_in_bitvector(int bitvector[],int rowlimit,int x)
{
    int bucketpos=x/32;
    if(bucketpos>=rowlimit)
    {
        cout<<"Capacity Exceed:-"<<endl;
        return;
    }
    int bitpos=x%32;
    cout<<"Bucket="<<bucketpos<<" "<<"Bit="<<bitpos<<endl;
    cout<<"Mask="<<(1<<bitpos)<<endl;
    bitvector[bucketpos]=bitvector[bucketpos] | (1<<bitpos);
}
bool ispresent(int bitvector[],int rowlimit,int x)
{
    int bucketpos=x/32;
    if(bucketpos>=rowlimit)
    {
        cout<<"Capacity Exceed:-"<<endl;
        return false;
    }
    int bitpos=x%32;
    int bit[32];
    for(int j=0;j<=31;j++)
        bit[j]=0;
    int temp=bitvector[bucketpos],sp=31;
    while(temp!=0)
    {
        if(temp%2==0)
            bit[sp--]=0;
        else
            bit[sp--]=1;
        temp=temp/2;
    }
    if(bit[32-bitpos-1]==1)
        return true;
    return false;
}
void binary(int bitvector[],int row)
{
    for(int i=0;i<5;i++)
    {
        int bit[32];
        for(int j=0;j<=31;j++)
            bit[j]=0;
        int temp=bitvector[i],sp=31;
        while(temp!=0)
        {
            if(temp%2==0)
                bit[sp--]=0;
            else
                bit[sp--]=1;
            temp=temp/2;
        }
        for(int j=0;j<32;j++)
            cout<<bit[j];
        cout<<endl;
    }
}
int main()
{
    int bitvector[5];
    for(int i=0;i<5;i++)
        bitvector[i]=0;
    int n;
    cout<<"Enter No. of Elements:-"<<endl;
    cin>>n;
    cout<<"Enter the Elements to be Count:-"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        add_in_bitvector(bitvector,5,x);
        binary(bitvector,5);
    }
    int q;
    cout<<"Enter Number of Queries:-"<<endl;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int y;
        cout<<"Enter the Element to be Checked:-"<<endl;
        cin>>y;
        if(ispresent(bitvector,5,y)==true)
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    }
    return 0;
}

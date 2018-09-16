#include<bits/stdc++.h>
using namespace std;
int item_val=0;
void knapsack(int capacity,int n,int weight[],int value[],int status[],int p)
{
    if(p==n)
    {
        int w=0,v=0;
        for(int i=0;i<n;i++)
        {
            if(status[i]==1)
            {
                v+=value[i];
                w+=weight[i];
            }
        }
        if(w<=capacity && v>=item_val)
            item_val=v;
        return;
    }
    status[p]=0;
    knapsack(capacity,n,weight,value,status,p+1);
    status[p]=1;
    knapsack(capacity,n,weight,value,status,p+1);
}
int main()
{
    int capacity;
    cout<<"Enter the Capacity of the Knapsack:-"<<endl;
    cin>>capacity;
    int n;
    cout<<"Enter the No. of items:-"<<endl;
    cin>>n;
    cout<<"Enter the Weight of Each Items:-"<<endl;
    int weight[n];
    for(int i=0;i<n;i++)
        cin>>weight[i];
    int value[n];
    cout<<"Enter the Values of the Items:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>value[i];
    int status[n],p=0;
    knapsack(capacity,n,weight,value,status,p);
    cout<<"Max Value="<<item_val<<endl;
    return 0;
}

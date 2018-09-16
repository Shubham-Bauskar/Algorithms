#include<bits/stdc++.h>
using namespace std;
void knapsack(int capacity,int n,int weight[],int value[])
{
    int lookup[n][capacity+1];
    for(int j=0;j<=capacity;j++)
    {
        if(weight[0]<=capacity)
            lookup[0][j]=value[0];
        else
            lookup[0][j]=0;
    }
    for(int i=0;i<n;i++)//If capacity of the knapsack is 0 then we can't pick any item so net value=0
        lookup[i][0]=0;
    for(int i=1;i<n;i++)//Check for Each Item
    {
        for(int j=1;j<=capacity;j++)//For each Capacity of Knapsack try to pick or leave the i-th item
        {
            if(j>=weight[i])//Capacity of knapsack is more than weight of i-th item so we can pick this item
            {
                //max(pick this item + full fill remaining weight with whatever best we have done so far; don't pick + whatever best done so far)
                lookup[i][j]=max(value[i]+lookup[i-1][j-weight[i]],lookup[i-1][j]);
            }
            else//Capacity of knapsack is less than weight of i-th item so we can't pick it.
                lookup[i][j]=lookup[i-1][j];//Whatever best we had done so far
        }
    }
    cout<<"LookUP:-"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=capacity;j++)
            cout<<lookup[i][j]<<" ";
        cout<<endl;
    }
    cout<<"MAX VALUE="<<lookup[n-1][capacity]<<endl;
    vector<int> items;
    int i=n-1,j=capacity;
    while(j>0 && i>0)
    {
       int top=lookup[i-1][j];
       if(top==lookup[i][j])//then we come from top i.e we haven't choose the i-th item
         i--;
       else
       {
           items.push_back(weight[i]);
           j-=weight[i];
           i--;
       }
    }
    cout<<"Items Picked:-"<<endl;
    for(int i=0;i<items.size();i++)
        cout<<items[i]<<" ";
    cout<<endl;
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
    knapsack(capacity,n,weight,value);
    return 0;
}

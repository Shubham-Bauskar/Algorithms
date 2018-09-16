#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Processes:-"<<endl;
    int n;
    cin>>n;
    int m;
    cout<<"Enter the Number of Resources:-"<<endl;
    cin>>m;
    int max_need[n][m];//Maximum Need of Resources
    cout<<"Enter the Maximum Need of Resources to all Process:-"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          cin>>max_need[i][j];
    cout<<"Enter the Current Resource Allocation:-"<<endl;
    int curr_allocation[n][m];//Current Allocation of Resources
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          cin>>curr_allocation[i][j];
    cout<<"Current Available Resources:-"<<endl;
    int available[m];
    for(int i=0;i<m;i++)
        cin>>available[i];
    int remaining_need[n][m];//Remaining need of the Resources
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           remaining_need[i][j]=max_need[i][j]-curr_allocation[i][j];
    vector<int> order;
    int status[n];
    for(int i=0;i<n;i++)
        status[i]=0;
    int it;
    for(it=0;it<n;it++)
    {
        for(int j=0;j<n;j++)
        {
            if(status[j]==0)//Not Full-Filled the Request
            {
                int flag=1;//Assuming at this instance all its need for resources can be fulfilled
                for(int t=0;t<m;t++)
                {
                    if(available[t]<remaining_need[j][t])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)//Execute this Process by FullFilling its need for Resources & Deallocate all the Resources
                {
                    for(int t=0;t<m;t++)//Allocating the Resources
                        available[t]-=remaining_need[j][t];
                    for(int t=0;t<m;t++)
                        available[t]+=max_need[j][t];
                    status[j]=1;
                    order.push_back(j);
                    break;
                }
            }
        }
    }
    if(order.size()==n)//Safe Execution Order Found
    {
        cout<<"Safe Execution Order:-"<<endl;
        for(int i=0;i<order.size();i++)
            cout<<"P"<<order[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"No Safe Execution Order Found"<<endl;
    return 0;
}
/*
Test Case
# of Process=5
# of Resource=3
maximum need
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
current allocation
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
current available resource
3 3 2
*/

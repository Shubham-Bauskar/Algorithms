#include<bits/stdc++.h>
using namespace std;
bool find(vector<int> &v,int high,int id)
{
    for(int i=0;i<=high;i++)
    {
        if(v[i]==id)
            return true;
    }
    return false;
}
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
    int order[n];
    cout<<"Enter the Process Id's(Execution Trace):-"<<endl;
    for(int i=0;i<n;i++)
        cin>>order[i];
    cout<<"Remaining Need of Processes:-"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
           cout<<remaining_need[i][j]<<" ";
        cout<<endl;
    }
    int status[n];
    for(int i=0;i<n;i++)
        status[i]=0;
    int flag=1;
    vector<int> curr_satisfied_process;
    for(int i=0;i<n;i++)
    {
        int id=order[i];
        for(int j=0;j<n;j++)//For each incomplete Process Check
        {
            int flagt=-1;//Assuming Process can Now be Satisfied
            if(status[j]==0)
            {
                flagt=1;
                for(int x=0;x<m;x++)
                {
                    if(remaining_need[j][x]>available[x])
                    {
                        flagt=0;
                        break;
                    }
                }
            }
            if(flagt==1)//This Process Can be Satisfied
                curr_satisfied_process.push_back(j);
        }
        if(find(curr_satisfied_process,curr_satisfied_process.size()-1,id)==false)
        {//Wrong Execution Order
            flag=0;
            break;
        }
        else//till Now Order is Correct
        {
            for(int t=0;t<m;t++)
                available[t]+=max_need[id][t];
            status[id]=1;
        }
        curr_satisfied_process.clear();
    }
    if(flag==1)//Safe Execution Order Found
        cout<<"** Safe Execution Order **"<<endl;
    else
        cout<<"** No Safe Execution Order **"<<endl;
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
execution trace
1 3 4 0 2
execution trace
1 0 3 2 4
*/

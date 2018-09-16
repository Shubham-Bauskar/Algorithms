#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int size;
    int partition_no_first;
    int partition_no_best;
    int partition_no_worst;
};
struct partition
{
    int size;
    int status;
};
void first_fit(struct process p[],int n,struct partition par[],int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(par[j].status==0 && par[j].size>=p[i].size)//Partition is Empty & can Allocate the Process
            {
                par[j].status=1;
                p[i].partition_no_first=j;
                break;
            }
        }
    }
}
void worst_fit(struct process p[],int n,struct partition par[],int m)
{
    for(int i=0;i<n;i++)
    {
        int maxi=-1;
        //Find the Maximum Size Frame Which is Sufficient to Accommodate the Process
        for(int j=0;j<m;j++)
        {
            if(par[j].status==0 && par[j].size>=p[i].size)//Partition is Empty & can Allocate the Process
            {
                if(maxi==-1)//Allocate that Frame but search for Next Best Frame
                    maxi=j;
                else if(par[maxi].size<par[j].size)
                    maxi=j;
            }
        }
        if(maxi!=-1)//Suitable Partition Found
        {
            par[maxi].status=1;
            p[i].partition_no_worst=maxi;
        }
    }
}
void best_fit(struct process p[],int n,struct partition par[],int m)
{
    for(int i=0;i<n;i++)
    {
        int mini=-1;
        //Find the Minimum Size Frame Which is Sufficient to Accommodate the Process
        for(int j=0;j<m;j++)
        {
            if(par[j].status==0 && par[j].size>=p[i].size)//Partition is Empty & can Allocate the Process
            {
                if(mini==-1)//Allocate that Frame but search for Next Best Frame
                    mini=j;
                else if(par[mini].size>par[j].size)
                    mini=j;
            }
        }
        if(mini!=-1)//Suitable Partition Found
        {
            par[mini].status=1;
            p[i].partition_no_best=mini;
        }
    }
}
int main()
{
    cout<<"Enter the Number of Processes:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter Process-id & Process Size:-"<<endl;
    struct process p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].id>>p[i].size;
        p[i].partition_no_first=p[i].partition_no_best=p[i].partition_no_worst=-1;
    }
    cout<<"Enter Number of Partitions:-"<<endl;
    int m;
    cin>>m;
    struct partition par[m];
    int partition_status[m];
    cout<<"Enter Size & Status{1=Filled,0=Empty} of Each Partition:-"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>par[i].size>>par[i].status;
        partition_status[i]=par[i].status;
    }
    first_fit(p,n,par,m);
    cout<<endl<<"Process Status in Memory using First Fit Algorithm:-"<<endl;
    cout<<"Id"<<"\t"<<"Size"<<"\t"<<"Partition No."<<endl;
    for(int i=0;i<n;i++)
    {
         cout<<p[i].id<<"\t"<<p[i].size<<" ";
         if(p[i].partition_no_first==-1)
            cout<<"\t"<<"Not Allocated"<<endl;
         else
            cout<<"\t"<<"    "<<p[i].partition_no_first<<endl;
    }
    for(int i=0;i<m;i++)
        par[i].status=partition_status[i];
    best_fit(p,n,par,m);
    cout<<endl<<"Process Status in Memory using Best Fit Algorithm:-"<<endl;
    cout<<"Id"<<"\t"<<"Size"<<"\t"<<"Partition No."<<endl;
    for(int i=0;i<n;i++)
    {
         cout<<p[i].id<<"\t"<<p[i].size<<" ";
         if(p[i].partition_no_best==-1)
            cout<<"\t"<<"Not Allocated"<<endl;
         else
            cout<<"\t"<<"    "<<p[i].partition_no_best<<endl;
    }
    for(int i=0;i<m;i++)
        par[i].status=partition_status[i];
    worst_fit(p,n,par,m);
    cout<<endl<<"Process Status in Memory using Worst Fit Algorithm:-"<<endl;
    cout<<"Id"<<"\t"<<"Size"<<"\t"<<"Partition No."<<endl;
    for(int i=0;i<n;i++)
    {
         cout<<p[i].id<<"\t"<<p[i].size<<" ";
         if(p[i].partition_no_worst==-1)
            cout<<"\t"<<"Not Allocated"<<endl;
         else
            cout<<"\t"<<"    "<<p[i].partition_no_worst<<endl;
    }
    return 0;
}
/*
Test Case
process=5
1 500
2 50
3 100
4 300
5 200
partition=4
200 0
100 0
400 0
300 0
*/

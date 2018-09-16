#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int size;
    int partition_no;
};
struct partition
{
    int size;
    int status;
};
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
            p[i].partition_no=maxi;
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
        p[i].partition_no=-1;
    }
    cout<<"Enter Number of Partitions:-"<<endl;
    int m;
    cin>>m;
    struct partition par[m];
    cout<<"Enter Size & Status{1=Filled,0=Empty} of Each Partition:-"<<endl;
    for(int i=0;i<m;i++)
        cin>>par[i].size>>par[i].status;
    worst_fit(p,n,par,m);
    cout<<"Process Status in Memory {-1=No Partition Allocated}:-"<<endl;
    cout<<"Id"<<" "<<"Size"<<" "<<"Partition No."<<endl;
    for(int i=0;i<n;i++)
    {
         cout<<p[i].id<<"    "<<p[i].size<<" ";
         if(p[i].partition_no==-1)
            cout<<"   "<<"Not Allocated"<<endl;
         else
            cout<<"   "<<p[i].partition_no<<endl;
    }
    return 0;
}

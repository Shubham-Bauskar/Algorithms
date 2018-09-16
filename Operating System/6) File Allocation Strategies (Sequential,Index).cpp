#include<bits/stdc++.h>
using namespace std;
struct file
{
    int id;
    int size;
    int start_block;
    int allocation_status;
};
struct file_index
{
    int id;
    int size;
    int index_block;
    vector<int> block_occupy;
    int allocation_status;
};
void sequential_allocation(struct file f[],int m,int n,int block[],int st_block[])
{
    for(int i=0;i<m;i++)//Try to Allocate each File
    {
        int low=f[i].start_block;
        int high=f[i].start_block+f[i].size-1;
        int flag=1;
        for(int j=low;j<=high;j++)
        {
            if(st_block[j]==1)//Block is Full
            {
                flag=0;
                break;
            }
        }
        if(flag==0)//No Allocation Possible
            f[i].allocation_status=0;
        else//Allocation Possible
        {
            for(int j=low;j<=high;j++)
            {
                block[j]=i;
                st_block[j]=1;
            }
            f[i].allocation_status=1;
        }
    }
}
bool is_possible_allocate(int st_block[],int count,int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(st_block[i]==-1)
            temp++;
    }
    if(temp>=count)
        return true;
    return false;
}
void index_allocation(struct file_index fi[],int m,int n,int block[],int st_block[])
{
    for(int i=0;i<m;i++)//Try to Allocate Each File
    {
       bool flag=is_possible_allocate(st_block,fi[i].size+1,n);
       if(flag==false)//Allocation Not Possible
           fi[i].allocation_status=0;
       else//Allocation Possible
       {
           fi[i].allocation_status=1;
           int temp=0,j;
           for(j=0;j<n;j++)
           {
               if(st_block[j]==-1)//Block is Vacant assign file
               {
                   block[j]=i;
                   st_block[j]=1;
                   fi[i].block_occupy.push_back(j);
                   temp++;
               }
               if(temp==fi[i].size)
                 break;
           }
           while(j<n)
           {
               if(st_block[j]==-1)//Block is Vacant assign index_block
               {
                   fi[i].index_block=j;
                   fi[i].block_occupy.push_back(j);
                   st_block[j]=1;
                   block[j]=i;
                   break;
               }
               j++;
           }
       }
    }
}
int main()
{
    cout<<"Enter Number of Blocks in the Disk:-"<<endl;
    int n;
    cin>>n;
    int block[n],st_block[n];
    for(int i=0;i<n;i++)
        st_block[i]=block[i]=-1;
    cout<<"Enter the Number of Files:-"<<endl;
    int m;
    cin>>m;
    struct file f[m];
    struct file_index fi[m];
    cout<<"Enter <Starting-Block Size> of File for Sequential Allocation Strategy:-"<<endl;
    for(int i=0;i<m;i++)
    {
        f[i].id=fi[i].id=i;
        cin>>f[i].start_block>>f[i].size;
        fi[i].size=f[i].size;
        f[i].allocation_status=fi[i].allocation_status=0;
        fi[i].index_block=-1;
    }
    sequential_allocation(f,m,n,block,st_block);
    cout<<endl<<"SEQUENTIAL ALLOCATION:-"<<endl;
    cout<<"File-Id  Status:-"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<i<<"\t";
        if(f[i].allocation_status==0)
            cout<<"Not Allocated";
        else
            cout<<"Allocated";
        cout<<endl;
    }
    cout<<"Disk Block Status:-"<<endl;
    cout<<"Block"<<" "<<"File Id"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
        if(block[i]==-1)
            cout<<"-"<<" ";
        else
            cout<<block[i]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
        block[i]=st_block[i]=-1;
    index_allocation(fi,m,n,block,st_block);
    cout<<endl<<"INDEX ALLOCATION:-"<<endl;
    cout<<"File-Id  Status         Blocks-Occupied:-"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<i<<"\t";
        if(fi[i].allocation_status==0)
            cout<<"Not Allocated";
        else
        {
            cout<<"Allocated";
            cout<<"\t";
            for(int j=0;j<fi[i].block_occupy.size()-1;j++)
                cout<<fi[i].block_occupy[j]<<" ";
            cout<<" Index="<<fi[i].block_occupy[fi[i].block_occupy.size()-1];
        }
        cout<<endl;
    }
    cout<<"Disk Block Status:-"<<endl;
    cout<<"Block"<<" "<<"File Id"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t";
        if(block[i]==-1)
            cout<<"-"<<" ";
        else
            cout<<block[i]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
Test Case
# of Blocks=32
# of Files=5
start length(Sequential)
 0      2
 14     3
 19     6
 28     45
 6      2
length(Indexed)
 2
 3
 6
 4
 2
*/

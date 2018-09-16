#include<bits/stdc++.h>
using namespace std;
bool find(vector<int> &v,int x)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
            return true;
    }
    return false;
}
void fcfs(vector<int> &v,int n,int head)
{
    int totalseektime=0;
    for(int i=0;i<n;i++)
    {
        totalseektime+=abs(head-v[i]);
        head=v[i];
    }
    cout<<"Total Seek Time="<<totalseektime<<endl;
    cout<<"Average Seek Time="<<1.0*totalseektime/n<<endl;
}
void scan(vector<int> &v,int n,int head,int low,int high)
{
    int headi=head;
    int totalseektime=0,left=n;
    while(left!=0)
    {
        int flag=1;
        for(int i=head;i<=high;i++)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        totalseektime+=high-head;
        totalseektime+=high-headi;
        head=headi;
        for(int i=headi;i>=low;i--)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)
            break;
    }
    cout<<"Total Seek Time="<<totalseektime<<endl;
    cout<<"Average Seek Time="<<1.0*totalseektime/n<<endl;
}
void look(vector<int> &v,int n,int head,int low,int high)
{
    int headi=head;
    int min=v[0],max=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<min)
            min=v[i];
        if(v[i]>max)
            max=v[i];
    }
    high=max;
    low=min;
    int totalseektime=0,left=n;
    while(left!=0)
    {
        int flag=1;
        for(int i=head;i<=high;i++)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        totalseektime+=high-head;
        totalseektime+=high-headi;
        head=headi;
        for(int i=headi;i>=low;i--)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)
            break;
    }
    cout<<"Total Seek Time="<<totalseektime<<endl;
    cout<<"Average Seek Time="<<1.0*totalseektime/n<<endl;
}
void cscan(vector<int> &v,int n,int head,int low,int high)
{
    int headi=head;
    int totalseektime=0,left=n;
    while(left!=0)
    {
        int flag=1;
        for(int i=head;i<=high;i++)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        totalseektime+=high-head;
        totalseektime+=high-low+1;
        head=0;
        for(int i=0;i<headi;i++)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)
            break;
    }
    cout<<"Total Seek Time="<<totalseektime<<endl;
    cout<<"Average Seek Time="<<1.0*totalseektime/n<<endl;
}
void clook(vector<int> &v,int n,int head,int low,int high)
{
    int headi=head;
    int totalseektime=0,left=n;
    int min=v[0],max=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<min)
            min=v[i];
        if(v[i]>max)
            max=v[i];
    }
    high=max;
    low=min;
    while(left!=0)
    {
        int flag=1;
        for(int i=head;i<=high;i++)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        totalseektime+=high-head;
        totalseektime+=max-min;
        head=min;
        for(int i=min;i<headi;i++)
        {
            if(find(v,i)==true)
            {
                totalseektime+=abs(head-i);
                head=i;
                left--;
                if(left==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)
            break;
    }
    cout<<"Total Seek Time="<<totalseektime<<endl;
    cout<<"Average Seek Time="<<1.0*totalseektime/n<<endl;
}
void sstf(vector<int> v,int n,int head)
{
    int st[n],totalseektime=0;
    for(int i=0;i<n;i++)
        st[i]=0;
    int left=n;
    while(left!=0)
    {
        //Calculate least Head Movement
        int hm=9999999,pos=-1;
        for(int i=0;i<n;i++)
        {
            if(st[i]==0)//Not Served
            {
                int x=abs(head-v[i]);
                if(x<hm)
                {
                    hm=x;
                    pos=i;
                }
            }
        }
        if(pos!=-1)
        {
            totalseektime+=abs(head-v[pos]);
            head=v[pos];
            st[pos]=1;
            left--;
            if(left==0)
                break;
        }
        else
            break;
    }
    cout<<"Total Seek Time="<<totalseektime<<endl;
    cout<<"Average Seek Time="<<1.0*totalseektime/n<<endl;
}
int main()
{
    cout<<"Enter input Range of Disk"<<endl;
    int low,high;
    cin>>low>>high;
    cout<<"Enter initial Head Position:-"<<endl;
    int head;
    cin>>head;
    cout<<"Enter No. of Queue Request"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Request:-"<<endl;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<endl<<"FCFS:-"<<endl;
    fcfs(v,n,head);
    cout<<endl<<"SCAN(direction=right):-"<<endl;
    scan(v,n,head,low,high);
    cout<<endl<<"CSCAN(direction=right):-"<<endl;
    cscan(v,n,head,low,high);
    cout<<endl<<"SSTF:-"<<endl;
    sstf(v,n,head);
    cout<<endl<<"LOOK(direction=right):-"<<endl;
    look(v,n,head,low,high);
    cout<<endl<<"CLOOK(direction=right):-"<<endl;
    clook(v,n,head,low,high);
    return 0;
}
/*
Test Case
disk range=0 199
initial head position=53
no of request=8
Request Queue
98 183 37 122 14 124 65 67
*/

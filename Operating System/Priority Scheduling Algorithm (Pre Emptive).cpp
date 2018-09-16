#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id,arrival;
    int cpu,completion,cputemp;
    int wait,turn;
    int status;
    int priority;
};
int findmin_priority(vector<int> &v,struct process p[],int n)
{
    int mini=v[0],min=p[v[0]].priority;
    for(int i=1;i<v.size();i++)
    {
        if(p[v[i]].priority<min)
        {
            min=p[v[i]].priority;
            mini=v[i];
        }
    }
    return mini;
}
int main()
{
    cout<<"Enter the Number of Processes:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter < Process-id CPU-Burst Arrival-Time Priority(0=highest):-"<<endl;
    struct process p[n];
    int tf=0;
    for(int i=0;i<n;i++)
    {
         cin>>p[i].id>>p[i].cpu>>p[i].arrival>>p[i].priority;
         p[i].status=0;//0=Not Completed & 1=Completed
         tf+=p[i].cpu;
         p[i].cputemp=p[i].cpu;
    }
    int ti=0;
    while(ti<tf)
    {
        //Find all the Processes that arrive before or at ti and status=0.
        vector<int> index;
        for(int i=0;i<n;i++)
        {
            if(p[i].arrival<=ti && p[i].status==0)//Process arrive at or before "ti" & not executed
                index.push_back(i);
        }
        if(index.size()==0)//No Process is Present
            ti++;
        else
        {
            int id=findmin_priority(index,p,n);//This function will return the process id which is to be chosen next to execute
            ti++;
            p[id].cpu--;
            if(p[id].cpu==0)
            {
                p[id].status=1;
                p[id].completion=ti;
                p[id].turn=p[id].completion-p[id].arrival;
                p[id].wait=p[id].turn-p[id].cputemp;
            }
        }
    }
    float avgT=0,avgW=0;
    cout<<"GANTT CHART:-"<<endl;
    cout<<"Id    Arrival  CPU  Completion  Turn   Wait  Priority"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"\t"<<p[i].arrival<<"\t"<<p[i].cputemp<<"\t"<<p[i].completion;
        cout<<"\t"<<" "<<p[i].turn<<"\t"<<p[i].wait<<"\t"<<p[i].priority<<endl;
        avgT+=p[i].turn;
        avgW+=p[i].wait;
    }
    avgT=avgT/n;
    avgW=avgW/n;
    cout<<"Average Turn Around Time="<<avgT<<endl;
    cout<<"Average Waiting Time="<<avgW<<endl;
    return 0;
}
/*
Test case
1 4 0 2
2 2 1 4
3 3 2 6
4 5 3 10
5 1 4 8
6 4 5 12
7 6 6 9
*/

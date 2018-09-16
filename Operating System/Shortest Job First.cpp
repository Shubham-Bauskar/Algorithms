#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id,arrival;
    int cpu,completion;
    int wait,turn;
    int status;
};
int findmin_cpuburst(vector<int> &v,struct process p[],int n)
{
    int mini=v[0],min=p[v[0]].cpu;
    for(int i=1;i<v.size();i++)
    {
        if(p[v[i]].cpu<min)
        {
            min=p[v[i]].cpu;
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
    cout<<"Enter < Process-id CPU-Burst Arrival-Time> :-"<<endl;
    struct process p[n];
    int tf=0;
    for(int i=0;i<n;i++)
    {
         cin>>p[i].id>>p[i].cpu>>p[i].arrival;
         p[i].status=0;//0=Not Completed & 1=Completed
         tf+=p[i].cpu;
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
        int id=findmin_cpuburst(index,p,n);//This function will return the process id which is to be chosen next to execute
        p[id].status=1;
        ti+=p[id].cpu;
        p[id].completion=ti;
        p[id].turn=p[id].completion-p[id].arrival;
        p[id].wait=p[id].turn-p[id].cpu;
    }
    float avgT=0,avgW=0;
    cout<<"GANTT CHART:-"<<endl;
    cout<<"id Arrival CPU Completion Turn Wait"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"   "<<p[i].arrival<<"       "<<p[i].cpu<<"     "<<p[i].completion;
        cout<<"         "<<p[i].turn<<"   "<<p[i].wait<<endl;
        avgT+=p[i].turn;
        avgW+=p[i].wait;
    }
    avgT=avgT/n;
    avgW=avgW/n;
    cout<<"Average Turn Around Time="<<avgT<<endl;
    cout<<"Average Waiting Time="<<avgW<<endl;
    return 0;
}

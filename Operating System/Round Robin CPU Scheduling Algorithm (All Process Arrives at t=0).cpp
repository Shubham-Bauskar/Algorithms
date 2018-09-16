#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int cpu,completion,cputemp;
    int wait,turn;
    int status;
};
int main()
{
    cout<<"Enter the Number of Processes:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter < Process-id CPU-Burst :-"<<endl;
    struct process p[n];
    int tf=0;
    for(int i=0;i<n;i++)
    {
         cin>>p[i].id>>p[i].cpu;
         p[i].status=0;//0=Not Completed & 1=Completed & 2=Currently Executed
         tf+=p[i].cpu;
         p[i].cputemp=p[i].cpu;
    }
    cout<<"Enter the Time Quantum:-"<<endl;
    int tc;
    cin>>tc;

    //ROUND ROBIN ALGORITHM
    int ti=0;
    while(1)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(p[i].status==0)//Process is Not Terminated
            {
                if(p[i].cpu<=tc)//CPU Burst is Less than Time Quantum
                {
                    ti+=p[i].cpu;
                    p[i].cpu=0;
                    p[i].status=1;
                    p[i].completion=ti;
                    p[i].turn=p[i].completion;
                    p[i].wait=p[i].turn-p[i].cputemp;
                }
                else//More CPU burst left
                {
                    ti+=tc;
                    p[i].cpu-=tc;
                }
            }
            if(ti>=tf)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    //PROCESS GANTT CHART
    float avgT=0,avgW=0;
    cout<<"GANTT CHART:-"<<endl;
    cout<<"Id  CPU     Completion  Turn   Wait"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"   "<<p[i].cputemp<<"\t";
        cout<<"\t"<<p[i].completion;
        cout<<"\t"<<p[i].turn<<"\t"<<p[i].wait<<endl;
        avgT+=p[i].turn;
        avgW+=p[i].wait;
    }
    avgT=avgT/n;
    avgW=avgW/n;
    cout<<"Average Turn Around Time="<<avgT<<endl;
    cout<<"Average Waiting Time="<<avgW<<endl;
    return 0;
}



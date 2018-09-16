#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id,arrival;
    int cpu,completion,cputemp;
    int wait,turn;
    int status;
};
int main()
{
    cout<<"Enter the Number of Processes:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter < Process-id CPU-Burst Arrival-Time >:-"<<endl;
    struct process p[n];
    int tf=0;
    for(int i=0;i<n;i++)
    {
         cin>>p[i].id>>p[i].cpu>>p[i].arrival;
         p[i].status=0;//0=Not Completed & 1=Completed & 2=Currently Executed
         tf+=p[i].cpu;
         p[i].cputemp=p[i].cpu;
    }
    cout<<"Enter the Time Quantum:-"<<endl;
    int tc;
    cin>>tc;

    //ROUND ROBIN ALGORITHM
    int ti=p[0].arrival,mini=0;
    for(int i=1;i<n;i++)
    {
        if(ti>p[i].arrival)
        {
            mini=i;
            ti=p[i].arrival;
        }
    }
    queue<int> q;
    q.push(mini);
    while(ti<=tf)
    {
        if(q.empty()==true)//No Process is Present in Ready Queue => CPU is ideal.
            ti++;
        else
        {
            int id=q.front();//This function will return the process id which is to be chosen next to execute
            cout<<id+1;
            q.pop();
            cout<<"("<<p[id].cpu<<")";
            if(p[id].cpu<=tc)
            {
                ti+=p[id].cpu;
                p[id].cpu=0;
            }
            else if(p[id].cpu>tc)
            {
                ti+=tc;
                p[id].cpu-=tc;
            }
            cout<<"("<<p[id].cpu<<")"<<" ";
            //Search & Schedule Next Process which arrives before or at completion of CPU burst by process="id"
            for(int i=0;i<n;i++)
            {
                if(p[i].status==0 && p[i].cpu>0 && p[i].arrival<=ti && i!=id)//Process arrive at or before "ti" & not executed
                    q.push(i);
            }
            if(p[id].cpu==0)//Process Completes its Execution or CPU Burst
            {
                p[id].status=1;
                p[id].completion=ti;
                p[id].turn=p[id].completion-p[id].arrival;
                p[id].wait=p[id].turn-p[id].cputemp;
            }
            if(p[id].cpu>0)//Process Require CPU again to Complete
                q.push(id);
        }
    }

    //PROCESS GANTT CHART
    float avgT=0,avgW=0;
    cout<<endl<<"GANTT CHART:-"<<endl;
    cout<<"Id    Arrival  CPU  Completion  Turn   Wait"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"\t"<<p[i].arrival<<"\t"<<p[i].cputemp<<"\t"<<p[i].completion;
        cout<<"\t"<<" "<<p[i].turn<<"\t"<<p[i].wait<<endl;
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
Test Case
1 10 3
2 1 1
3 2 4
4 1 5
5 5 2
*/

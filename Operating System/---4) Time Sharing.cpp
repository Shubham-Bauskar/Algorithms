#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int cpu1,cpu2;
    int io;
    int completion;
    int turn;
    int io_cpu;//0=CPU1 && 1=I/O 2=CPU2
    int status_io_cpu;//0=CPU 1=I/O;
    int terminated;//1=Terminated 0=Not Terminated
};
int select_process_for_cpu(struct process p[],float tf)
{
    for(int i=0;i<3;i++)
    {
        if(p[i].status_io_cpu==1 && p[i].terminated==0)//Process is Performing IO
        {
            if(p[i].completion+p[i].io<=tf)//Process has completed its IO burst
            {
                p[i].status_io_cpu=0;
                p[i].io_cpu=2;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        if(p[i].terminated==0 && p[i].status_io_cpu==0)//Process has CPU burst left
            return i;
    }
    int terminate=1;
    for(int i=0;i<3;i++)
    {
        if(p[i].terminated==0)
            terminate=0;
    }
    if(terminate==1)
        return -1;
    return 100;
}
int main()
{
    struct process p[3];
    cout<<"Enter the CPU IO CPU Burst for 3 Processes:-"<<endl;
    for(int i=0;i<3;i++)
    {
         cin>>p[i].cpu1>>p[i].io>>p[i].cpu2;
         p[i].id=i;
         p[i].io_cpu=0;//First Burst in CPU
         p[i].status_io_cpu=0;
         p[i].terminated=0;
         p[i].completion=0;
    }
    int time=10;
    float avgT=0,io=0;
    int tf=0;
    cout<<endl<<"GANTT CHART:-"<<endl;
    cout<<"id   Completion  TurnAT  "<<endl;
    float cpuburst=0;
    while(true)
    {
        int id=select_process_for_cpu(p,tf);
        if(id==100)
        {
            tf++;
            continue;
        }
        if(id==-1)
            break;
        if(p[id].io_cpu==2)//Last CPU Burst
        {
            if(p[id].cpu2<=10)//Terminate the Process
            {
                tf+=p[id].cpu2;
                p[id].cpu2=0;
                p[id].terminated=1;
            }
            if(p[id].cpu2>10)
            {
               tf+=10;
               p[id].cpu2-=10;
            }
        }
        if(p[id].io_cpu==0)//First CPU Burst
        {
            if(p[id].cpu1<=10)//Terminate the Process
            {
                tf+=p[id].cpu1;
                p[id].cpu1=0;
                p[id].status_io_cpu=1;
                p[id].io_cpu=1;
            }
            if(p[id].cpu1>10)
            {
               tf+=10;
               p[id].cpu1-=10;
            }
        }
        p[id].completion=tf;
    }
    for(int i=0;i<3;i++)
    {
        p[i].turn=p[i].completion;
        avgT+=p[i].turn;
        cpuburst+=p[i].cpu1+p[i].cpu2;
        io+=p[i].io;
    }
    for(int i=0;i<3;i++)
        cout<<p[i].id<<"\t"<<p[i].completion<<"\t"<<"  "<<p[i].turn<<endl;
    cout<<endl<<"Total Turn Around Time="<<int(avgT)<<endl;
    cout<<"Average Turn Around Time="<<avgT/3<<endl;
    cout<<"CPU Utilization="<<cpuburst*100/tf<<endl;
    cout<<"IO Utilization="<<io*100/tf<<endl;
    cout<<"ThroughPut="<<3.0/tf<<endl;
    return 0;
}
/* Test Case
100 30 30
80 50 20
60 40 30
*/

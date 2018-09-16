#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int cpu1,cpu2;
    int io;
    int completion;
    int turn,wait;
};
int main()
{
    struct process p[3];
    cout<<"Enter the CPU IO CPU Burst for 3 Processes:-"<<endl;
    for(int i=0;i<3;i++)
    {
         cin>>p[i].cpu1>>p[i].io>>p[i].cpu2;
         p[i].id=i;
    }
    int ti=0,tf=0;
    float avgT=0,avgW=0;
    cout<<endl<<"GANTT CHART:-"<<endl;
    cout<<"id   Completion  TurnAT  WaitT"<<endl;
    float cpuburst=0;
    for(int i=0;i<3;i++)
    {
       tf=ti+p[i].cpu1+p[i].io+p[i].cpu2;
       cpuburst+=p[i].cpu1+p[i].cpu2;
       p[i].completion=tf;
       p[i].turn=p[i].completion;
       if(i==0)
           p[i].wait=0;
       else
           p[i].wait=p[i-1].completion;
       cout<<"P"<<p[i].id<<"      "<<p[i].completion<<"       "<<p[i].turn<<"     "<<p[i].wait<<" "<<endl;
       ti=tf;
       avgT+=p[i].turn;
       avgW+=p[i].wait;
    }
    cout<<endl<<"Total Turn Around Time="<<int(avgT)<<endl;
    cout<<"Average Turn Around Time="<<avgT/3<<endl;
    cout<<"Average Waiting Time="<<avgW/3<<endl;
    cout<<"CPU Utilization="<<cpuburst*100/tf<<endl;
    cout<<"IO Utilization="<<100-(cpuburst*100)/tf<<endl;
    cout<<"ThroughPut="<<3.0/tf<<endl;
    return 0;
}
/* Test Case
100 30 30
80 50 20
60 40 30
*/

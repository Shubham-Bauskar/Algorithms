#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id,arrival;
    int cpu,completion;
    int wait,turn;
};
int partition(struct process p[],int low,int high)
{
    int loc=low,left=low,right=high;
    while(true)
    {
        while(p[loc].arrival<=p[right].arrival && loc!=right)
          right--;
        if(loc==right)
            break;
        else//Swap
        {
            struct process temp=p[loc];
            p[loc]=p[right];
            p[right]=temp;
            loc=right;
        }
        while(p[loc].arrival>=p[left].arrival && loc!=left)
          left++;
        if(loc==left)
            break;
        else//Swap
        {
            struct process temp=p[loc];
            p[loc]=p[left];
            p[left]=temp;
            loc=left;
        }
    }
    return loc;
}
void quicksort(struct process p[],int low,int high)
{
    if(low<high)
    {
        int par=partition(p,low,high);
        quicksort(p,low,par-1);
        quicksort(p,par+1,high);
    }
}
int main()
{
    cout<<"Enter the Number of Processes:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter < Process-id Arrival-Time CPU-Burst > :-"<<endl;
    struct process p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].id>>p[i].arrival>>p[i].cpu;
    quicksort(p,0,n-1);
    for(int i=0;i<n;i++)
        cout<<p[i].id<<" ";
    cout<<endl;
    int ti=p[0].arrival,tf;
    float avgT=0,avgW=0;
    cout<<"GANTT CHART:-"<<endl;
    cout<<"Id Arrival Completion TurnAT WaitT"<<endl;
    for(int i=0;i<n;i++)
    {
       if(p[i].arrival>ti)
       {
           ti++;
           tf++;
           i--;
           continue;
       }
       tf=ti+p[i].cpu;
       p[i].completion=tf;
       p[i].turn=p[i].completion-p[i].arrival;
       p[i].wait=p[i].turn-p[i].cpu;
       cout<<"P"<<p[i].id<<"     "<<p[i].arrival<<"      "<<p[i].completion<<"       "<<p[i].turn<<"     "<<p[i].wait<<" "<<endl;
       ti=tf;
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
# of Process=3
id arrival CPU
0    12     5
1     2     5
2     3     4

# of Process=5
id arrival CPU
1     0     12
2     2     2
3     6     4
4     7     1
5     10    8
*/

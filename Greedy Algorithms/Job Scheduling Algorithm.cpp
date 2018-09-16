#include<bits/stdc++.h>
using namespace std;
struct job
{
   int id;
   int profit,deadline;
};
int partition(struct job a[],int low,int high)
{
    int left=low,right=high;
    int loc=low;
    while(1)
    {
        while(a[loc].profit<=a[right].profit && right!=loc)
            right--;
        if(loc==right)
            break;
        else
        {
            int temp=a[loc].profit;
            a[loc].profit=a[right].profit;
            a[right].profit=temp;

            temp=a[loc].id;
            a[loc].id=a[right].id;
            a[right].id=temp;

            temp=a[loc].deadline;
            a[loc].deadline=a[right].deadline;
            a[right].deadline=temp;

            loc=right;
        }
        while(a[loc].profit>=a[left].profit && left!=loc)
            left++;
        if(loc==left)
            break;
        else
        {
            int temp=a[loc].profit;
            a[loc].profit=a[left].profit;
            a[left].profit=temp;

            temp=a[loc].id;
            a[loc].id=a[left].id;
            a[left].id=temp;

            temp=a[loc].deadline;
            a[loc].deadline=a[left].deadline;
            a[left].deadline=temp;

            loc=left;
        }
    }
    return loc;
}
void quicksort(struct job arr[],int low,int high)
{
    if(low<high)
    {
      int mid=partition(arr,low,high);
      quicksort(arr,low,mid-1);
      quicksort(arr,mid+1,high);
    }
}
int main()
{
    cout<<"Enter the Number of Jobs:-"<<endl;
    int n;
    cin>>n;
    struct job j[n];
    cout<<"Enter Job id, Profit & DeadLine:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>j[i].id>>j[i].profit>>j[i].deadline;
    quicksort(j,0,n-1);
    int sequence[j[n-1].deadline+1];
    int status[j[n-1].deadline+1];
    for(int i=0;i<=n;i++)
        status[i]=0;
    int profit=0;
    for(int i=n-1;i>=0;i--)
    {
       int flag=0,pos=-1;
       for(int x=j[i].deadline;x>=1;x--)
       {
           if(status[x]==0)//Vacant Slot Found
           {
               flag=1;
               pos=x;
               break;
           }
       }
       if(flag==1)
       {
          status[pos]=1;
          sequence[pos]=j[i].id;
          profit+=j[i].profit;
       }
    }
    cout<<"Sequence is=";
    for(int i=1;i<=j[n-1].deadline+1;i++)
    {
        if(status[i]==1)
            cout<<sequence[i]<<" ";
        else
            cout<<"-"<<" ";
    }
    cout<<endl<<"PROFIT="<<profit<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void min_steps(int a[],int n)
{
    int noofsteps[n];
    for(int i=0;i<n;i++)
        noofsteps[i]=INT_MAX;
    noofsteps[0]=0;
    int steps[n];
    steps[0]=-1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j+a[j]>=i)//i lies in the jumping range
            {
                int x=1+noofsteps[j];
                if(x<noofsteps[i])
                {
                    noofsteps[i]=x;
                    steps[i]=j;
                }
            }
        }
    }
    int i=n-1;
    vector<int> path;
    while(i!=-1)
    {
        path.push_back(i);
        i=steps[i];
    }
    reverse(path.begin(),path.end());
    cout<<"Minimum No of Steps="<<noofsteps[n-1]<<endl;
    cout<<"PATH:-"<<endl;
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<" ";
}
int main()
{
    cout<<"Enter the No. of Elements in the Array:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Array:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    min_steps(a,n);
    return 0;
}

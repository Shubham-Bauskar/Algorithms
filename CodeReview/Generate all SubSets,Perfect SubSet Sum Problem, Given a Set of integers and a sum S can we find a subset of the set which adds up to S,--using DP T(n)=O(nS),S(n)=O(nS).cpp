#include<bits/stdc++.h>
using namespace std;
void subset_sum(int a[],int n,int sum)
{
    bool lookup[n][sum+1];//0=False & 1=True
    for(int i=0;i<n;i++)//Base Case since sum=0 we can always form an empty set since sum of elements of empty set=0
        lookup[i][0]=true;
    for(int j=1;j<=sum;j++)
    {
        if(j==a[0])
            lookup[0][j]=true;
        else//we cannot use a[0] element as it does not matches with sum
            lookup[0][j]=false;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<a[i])//sum is smaller so whatever best we have done so far
                lookup[i][j]=lookup[i-1][j];//can we be able to find a subset by considering only (i-1)elements
            else if(j>=a[i])//we can use this element
                lookup[i][j]=lookup[i-1][j]||lookup[i-1][j-a[i]];
            //here we have 2 choices completely exclude the i-th element and check whatever best we had done by considering
            //(i-1) elements or, pick i-th element & check can we find a subset for remaining sum i.e j-a[i]
        }
    }
    if(lookup[n-1][sum]!=true)
        cout<<"No Set Found"<<endl;
    else
    {
        cout<<"Set Found"<<endl;
        for(int t=n-1;t>=0;t--)
        {
            if(lookup[t][sum]==true)
            {
                vector<int> v;
                int i=t,j=sum;
                while(i!=0 && j!=0)
                {
                    if(lookup[i-1][j]==true)//we came from top
                        i--;
                    else
                    {
                        v.push_back(a[i]);
                        j-=a[i];
                        i--;
                    }
                }
                for(int i=0;i<v.size();i++)
                    cout<<v[i]<<" ";
                cout<<endl;
            }
        }
    }
}
int main()
{
    cout<<"Enter the Number of Elements in the Set:-"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the Elements in the Set:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Sum:-"<<endl;
    int sum;
    cin>>sum;
    subset_sum(a,n,sum);
    return 0;
}


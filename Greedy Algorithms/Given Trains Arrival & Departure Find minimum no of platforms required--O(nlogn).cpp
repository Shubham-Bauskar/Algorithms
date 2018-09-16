#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Number of Trains:-"<<endl;
    cin>>n;
    vector<float> arr,dept;
    cout<<"Enter Arrival Time-"<<endl;
    for(int i=0;i<n;i++)
    {
        float x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Enter Departure Time-"<<endl;
    for(int i=0;i<n;i++)
    {
        float x;
        cin>>x;
        dept.push_back(x);
    }
    sort(arr.begin(),arr.end());
    sort(dept.begin(),dept.end());
    int minplatform=1,result=0;
    int i=1,j=0;//Assuming Initially 1st train arrived at station so 1 platform is occupied
    while(i<n && j<n)
    {
        if(arr[i]<dept[j])
        {
            minplatform++;
            i++;
            if(result<minplatform)
                result=minplatform;
        }
        else
        {
            minplatform--;
            j++;
        }
    }
    cout<<"Minimum Platform Needed="<<result<<endl;
    return 0;
}

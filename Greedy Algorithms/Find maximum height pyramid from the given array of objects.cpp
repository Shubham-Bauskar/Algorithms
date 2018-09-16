#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Objects:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Width of Each Object:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    int prev_width=a[0],prev_count=0;
    int curr_count=0,curr_width=0;
    for(int i=1;i<n;i++)
    {
        curr_width+=a[i];
        curr_count++;
        if(curr_width>prev_width && curr_count>prev_count)
        {
            prev_count=curr_count;
            prev_width=curr_width;
            curr_count=curr_width=0;
            ans++;
        }
    }
    cout<<"Maximum Height of Pyramid that can be Formed="<<ans<<endl;
    return 0;
}

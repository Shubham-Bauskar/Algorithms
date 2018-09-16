#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Number of Bars:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Height of Each Bar:-"<<endl;
    int height[n];
    for(int i=0;i<n;i++)
        cin>>height[i];
    int area=0,low=-1,high=-1;
    for(int i=0;i<n;i++)
    {
        int min=height[i];
        for(int j=i;j<n;j++)
        {
            if(height[j]<min)
                min=height[j];
            int width=j-i+1;
            if(area<width*min)
            {
                area=width*min;
                low=i;
                high=j;
            }
        }
    }
    cout<<"Largest Rectangular Area="<<area<<endl;
    cout<<"Low-High="<<low<<" "<<high<<endl;
    return 0;
}

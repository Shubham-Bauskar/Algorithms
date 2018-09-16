#include<bits/stdc++.h>
using namespace std;
struct building
{
    int left,right;
    int height;
};
int main()
{
    cout<<"Enter Number of Buildings:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter left,right Coordinate & Height:-"<<endl;
    struct building b[n];
    for(int i=0;i<n;i++)
        cin>>b[i].left>>b[i].right>>b[i].height;
    vector<pair<int,int> >strip;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(b[i].right>max)
            max=b[i].right;
    }
    for(int i=1;i<max;i++)
    {
        vector<int> sizeofstrip;
        //For Each Building Check if it Lies in that range
        for(int j=0;j<n;j++)
        {
            if(b[j].left<=i && b[j].right>i)
                sizeofstrip.push_back(b[j].height);
        }
        int max;
        if(sizeofstrip.size()==0)
        {
            max=0;
            strip.push_back(make_pair(i,0));
            continue;
        }
        else
            max=sizeofstrip[0];
        for(int j=1;j<sizeofstrip.size();j++)
        {
            if(max<sizeofstrip[j])
                max=sizeofstrip[j];
        }
        strip.push_back(make_pair(i,max));
    }
    cout<<"Skyline:-"<<endl;
    for(int i=0;i<strip.size();)
    {
        pair<int,int> st=strip[i];
        int j=i+1;
        while(strip[j].second==st.second)
            j++;
        i=j;
        cout<<st.first<<" "<<st.second<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void  generate_all_length(int k,int sh,int lg,vector<int> &allsize)
{
    //Since to Place k Planks and order of planks doesn't matter
    //let t no. of short planks then place (k-t) larger planks
    for(int t=0;t<=k;t++)
    {
        int length=t*sh+(k-t)*lg;
        allsize.push_back(length);
    }
}
int main()
{
    cout<<"Enter No. of Planks to be Placed:-"<<endl;
    int k,sh,lg;
    cin>>k;
    cout<<"Enter the Size of Shorter & Longer Plank:-"<<endl;
    cin>>sh>>lg;
    vector<int> allsize;
    generate_all_length(k,sh,lg,allsize);
    cout<<"All Possible Size:-"<<endl;
    for(int i=0;i<allsize.size();i++)
        cout<<allsize[i]<<" ";
    cout<<endl;
}

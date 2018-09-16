#include<bits/stdc++.h>
using namespace std;
void  generate_all_length(int k,int total,int sh,int lg,vector<int> &allsize)
{
    if(k==0)//No Planks is Left to be Placed so whatever is the Total Length is the answer
    {
        allsize.push_back(total);
        return;
    }
    //Choose short plank to be placed next
    generate_all_length(k-1,total+sh,sh,lg,allsize);
    //Now choose large plank to be placed next
    generate_all_length(k-1,total+lg,sh,lg,allsize);
}
int main()
{
    cout<<"Enter No. of Planks to be Placed:-"<<endl;
    int k,sh,lg;
    cin>>k;
    cout<<"Enter the Size of Shorter & Longer Plank:-"<<endl;
    cin>>sh>>lg;
    vector<int> allsize;
    generate_all_length(k,0,sh,lg,allsize);
    cout<<"All Possible Size:-"<<endl;
    for(int i=0;i<allsize.size();i++)
        cout<<allsize[i]<<" ";
    cout<<endl;
}

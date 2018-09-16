#include<bits/stdc++.h>
using namespace std;
struct node
{
    int no_one;
    int total_val;
    int k_val;
};
vector<struct node> visited;
void  generate_all_length(int k,int total,int sh,int lg,vector<int> &allsize,int noofone)
{
    if(k==0)//No Planks is Left to be Placed so whatever is the Total Length is the answer
    {
        allsize.push_back(total);
        return;
    }
    //Check if this combination is already done or not
    if(visited.size()>0)
    {
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i].k_val==k && visited[i].total_val==total && visited[i].no_one==noofone)
                return;
        }
    }
    //Choose short plank to be placed next
    generate_all_length(k-1,total+sh,sh,lg,allsize,noofone);
    struct node p;
    p.no_one=noofone;
    p.k_val=k;
    p.total_val=total;
    visited.push_back(p);
    //Now choose large plank to be placed next
    generate_all_length(k-1,total+lg,sh,lg,allsize,noofone+1);
}
int main()
{
    cout<<"Enter No. of Planks to be Placed:-"<<endl;
    int k,sh,lg;
    cin>>k;
    cout<<"Enter the Size of Shorter & Longer Plank:-"<<endl;
    cin>>sh>>lg;
    vector<int> allsize;
    //noofone is the no. of long planks
    generate_all_length(k,0,sh,lg,allsize,0);
    cout<<"All Possible Size:-"<<endl;
    for(int i=0;i<allsize.size();i++)
        cout<<allsize[i]<<" ";
    cout<<endl;
}

#include<algorithm>
#include<iostream>
#include<vector>
bool check_pos_neg(int x)
{
    return x>0;
}
bool check_odd_even(int x)
{
    return x%2==0;
}
using namespace std;
int main()
{
    int a[]={2,-1,-15,-6,8,7,-9,12,-14,32,-68,-42};
    vector<int> v(a,a+12);
    cout<<"Partition on the Basis of Positive-Negative:-"<<endl;
    partition(v.begin(),v.end(),check_pos_neg);
    for(int i=0;i<12;i++)
        cout<<v[i]<<" ";
    cout<<endl<<"Stable Partition on the Basis of Positive-Negative:-"<<endl;
    stable_partition(v.begin(),v.end(),check_pos_neg);
    for(int i=0;i<12;i++)
        cout<<v[i]<<" ";
    cout<<endl<<"Partition on the Basis of Odd-Even:-"<<endl;
    partition(v.begin(),v.end(),check_odd_even);
    for(int i=0;i<12;i++)
        cout<<v[i]<<" ";
    cout<<endl<<"Stable Partition on the Basis of Odd-Even:-"<<endl;
    stable_partition(v.begin(),v.end(),check_odd_even);
    for(int i=0;i<12;i++)
        cout<<v[i]<<" ";
    return 0;
}

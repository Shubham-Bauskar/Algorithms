#include<bits/stdc++.h>
using namespace std;
bool isvalid(string a,int low,int high)
{
    int no=0,ch=0;
    for(int i=low;i<=high;i++)
    {
        if(a[i]>=48 && a[i]<=57)
            no++;
        else
            ch++;
    }
    if(no==ch)
        return true;
    return false;
}
int main()
{
    cout<<"Enter the String:-"<<endl;
    string a;
    cin>>a;
    int max_val=0,max_vali=-1;
    for(int l=2;l<=a.size();l+=2)
    {
        for(int i=0;i<=a.size()-l;i++)
        {
            if(isvalid(a,i,i+l-1)==true)
            {
                if(max_val<l)
                {
                    max_val=l;
                    max_vali=i;
                }
            }
        }
    }
    cout<<"Length of SubArray="<<max_val<<endl;;
    for(int i=max_vali;i<max_vali+max_val;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}

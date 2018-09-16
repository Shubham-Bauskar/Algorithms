#include<bits/stdc++.h>
using namespace std;
int compare(string a,string b)
{
    int min=a.size()<=b.size()?a.size():b.size();
    for(int i=0;i<min;i++)
    {
        if(a[i]>b[i])
            return 1;
        else if(a[i]<b[i])
            return -1;
    }
    if(a.size()<b.size())
        return -1;
    if(a.size()==b.size())
        return 0;
    return 1;
}
int binsearch(vector<string> &a,int low,int high,string to_be_search)
{
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(a[mid].size()==0)//Mid is of 0 length string then set mid to closest non empty string
    {
        int l=mid-1,r=mid+1;
        while(true)
        {
            if(l<low && r>high)
                return -1;
            else if(a[l].size()!=0 && l>=low)
            {
                mid=l;
                break;
            }
            else if(a[r].size()!=0 && r<=high)
            {
                mid=r;
                break;
            }
        }
    }
    //Now at this point mid is pointing to a non empty string
    int x=compare(a[mid],to_be_search);
    if(x==0)
        return mid;
    if(x==1)//Search in Left SubArray i.e a[mid]>val
        return binsearch(a,low,mid-1,to_be_search);
    return binsearch(a,mid+1,high,to_be_search);
}
int main()
{
    cout<<"Enter the Size of the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Strings in Sorted Order:-"<<endl;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    cout<<"Enter the String to be Searched:-"<<endl;
    string to_be_search;
    cin>>to_be_search;
    int pos=binsearch(v,0,n-1,to_be_search);
    if(pos>=0)
        cout<<"Found at Position="<<pos<<endl;
    else
        cout<<"Not Found"<<endl;
    return 0;
}
//Worst case time complexity for this problem is O(n);
//Worst Case occur when one non empty string and remaining all strings are of 0 length.

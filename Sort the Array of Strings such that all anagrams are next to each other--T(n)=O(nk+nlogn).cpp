#include<bits/stdc++.h>
using namespace std;
void computeascii(vector<string> &v,int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=0;
        string t=v[i];
        for(int j=0;j<t.size();j++)
            temp+=t[j]-97;
        a[i]=temp;
    }
}
int partition(int a[],vector<string> &v,int low,int high)
{
    int left=low,right=high;
    int loc=low;
    while(1)
    {
        while(a[loc]<=a[right] && right!=loc)
            right--;
        if(loc==right)
            break;
        else
        {
            int temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;


            string t=v[loc];
            v[loc]=v[right];
            v[right]=t;
            loc=right;
        }
        while(a[loc]>=a[left] && left!=loc)
            left++;
        if(loc==left)
            break;
        else
        {
            int temp=a[loc];
            a[loc]=a[left];
            a[left]=temp;

            string t=v[loc];
            v[loc]=v[left];
            v[left]=t;
            loc=left;
        }
    }
    return loc;
}
void quicksort(int arr[],vector<string> &v,int low,int high)
{
    if(low<high)
    {
      int mid=partition(arr,v,low,high);
      quicksort(arr,v,low,mid-1);
      quicksort(arr,v,mid+1,high);
    }
}
int main()
{
    cout<<"Enter the Number of Strings:-"<<endl;
    int n;
    cin>>n;
    vector<string> v;
    int ascii[n];
    cout<<"Enter the Strings:-"<<endl;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>ws>>s;
        v.push_back(s);
    }
    computeascii(v,ascii,n);
    quicksort(ascii,v,0,n-1);
    cout<<"Sorted Arrays Such that all Anagrams are next to each other:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}

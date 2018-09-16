#include<bits/stdc++.h>
using namespace std;
void maxheapifybottomup(vector<int> &a,int i)
{
    while(i>=1)
    {
        int p=i/2;
        if(a[p]<a[i])
        {
            int temp=a[p];
            a[p]=a[i];
            a[i]=temp;
        }
        i=i/2;
    }
}
void minheapifybottomup(vector<int> &a,int i)
{
    while(i>=1)
    {
        int p=i/2;
        if(a[p]>a[i])
        {
            int temp=a[p];
            a[p]=a[i];
            a[i]=temp;
        }
        i=i/2;
    }
}
void maxheapifytopbottom(vector<int> &a,int i,int limit)
{
    int ls=2*i,rs=2*i+1,pos=i;
    if(ls<=limit && a[ls]>a[pos])
        pos=ls;
    if(rs<=limit && a[rs]>a[pos])
        pos=rs;
    if(pos!=i)
    {
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
        maxheapifytopbottom(a,pos,limit);
    }
}
void minheapifytopbottom(vector<int> &a,int i,int limit)
{
    int ls=2*i,rs=2*i+1,pos=i;
    if(ls<=limit && a[ls]<a[pos])
        pos=ls;
    if(rs<=limit && a[rs]<a[pos])
        pos=rs;
    if(pos!=i)
    {
        int temp=a[pos];
        a[pos]=a[i];
        a[i]=temp;
        minheapifytopbottom(a,pos,limit);
    }
}
int deletemaxheap(vector<int> &h,int p)
{
    int x=h[1];
    int temp=h[p];
    h[p]=h[1];
    h[1]=temp;
    maxheapifytopbottom(h,1,p-1);
    return x;
}
int deleteminheap(vector<int> &h,int p)
{
    int x=h[1];
    int temp=h[p];
    h[p]=h[1];
    h[1]=temp;
    minheapifytopbottom(h,1,p-1);
    return x;
}

void balanceheap(vector<int> &left,vector<int> &right,int ls,int rs)
{
    while(abs(ls-rs)>1)
    {
        if(ls>rs)//left heap is heavier
        {
            int x=deletemaxheap(left,ls);
            ls--;
            right.push_back(x);
            rs++;
            minheapifybottomup(right,rs);
        }
        else
        {
            int x=deleteminheap(right,rs);
            rs--;
            left.push_back(x);
            ls++;
            maxheapifybottomup(left,ls);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> left,right;
    left.push_back(0);right.push_back(0);
    left.push_back(a[0]);
    int ls=1,rs=0;
    float prevm=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=prevm)
        {
            left.push_back(a[i]);
            ls++;
            maxheapifybottomup(left,ls);
        }
        else
        {
            right.push_back(a[i]);
            rs++;
            minheapifybottomup(right,rs);
        }
        balanceheap(left,right,ls,rs);
        //compute new median
        printf("%0.1f\n",prevm);
        if(ls==rs)//both have same size
            prevm=(left[1]+right[1])/2.0;
        else if(ls>rs)
            prevm=left[1];
        else 
            prevm=right[1];
    }
    return 0;
}
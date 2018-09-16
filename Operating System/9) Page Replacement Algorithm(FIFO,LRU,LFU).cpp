#include<bits/stdc++.h>
using namespace std;
bool find_page_frame(int f,int st[],int frame[],int pg_no)
{
    for(int i=0;i<f;i++)
    {
        if(st[i]==1 && frame[i]==pg_no)
            return true;
    }
    return false;
}
void fifo(int p,int f,int st[],vector<int> &req_page,int frame[])
{
    int pos_replaced=0,page_fault=0;
    vector<int> page;
    for(int i=0;i<req_page.size();i++)
    {
        int pos=find_page_frame(f,st,frame,req_page[i]);
        if(pos==false)//Page Fault Apply FIFO Page Replacement Algorithm
        {
            frame[pos_replaced]=req_page[i];
            st[pos_replaced]=1;
            pos_replaced=(pos_replaced+1)%f;
            page_fault++;
            page.push_back(req_page[i]);
        }
    }
    cout<<endl<<"FIFO:-"<<endl;
    cout<<endl<<"No. of Page Faults="<<page_fault<<endl;
    cout<<"Pages For Which Page Fault Occurs:-"<<endl;
    for(int i=0;i<page.size();i++)
        cout<<page[i]<<" ";
    cout<<endl;
}
int getid(int f,int frame_st[])
{
    int max=-1,maxi=-1;
    for(int i=0;i<f;i++)
    {
        if(max<frame_st[i])//Not Frequently used
        {
            max=frame_st[i];
            maxi=i;
        }
    }
    return maxi;
}
void optimal_lfu(int p,int f,int st[],vector<int> &req_page,int frame[])
{
    int page_fault=0,pos_replaced=0;
    vector<int> page;
    for(int i=0;i<req_page.size();i++)
    {
        int pos=find_page_frame(f,st,frame,req_page[i]);
        if(pos==false)//Page Fault Apply FIFO Page Replacement Algorithm
        {
            page_fault++;
            page.push_back(req_page[i]);
            if(pos_replaced<f)//Frames are Vacant
            {
                frame[pos_replaced]=req_page[i];
                st[pos_replaced]=1;
                pos_replaced++;
            }
            else//Frames are Full Vacant them by using LFU
            {
                for(int j=0;j<f;j++)
                    cout<<frame[j]<<" ";
                cout<<endl;
                int frame_st[f];
                for(int j=0;j<f;j++)
                    frame_st[j]=-1;
                int max=0;
                for(int j=i+1;j<req_page.size();j++)
                {
                    for(int x=0;x<f;x++)
                    {
                        if(frame[x]==req_page[j] && frame[x]==-1)
                        {
                            frame_st[x]=max;
                            max++;
                        }
                    }
                }
                int pos=getid(f,frame_st);
                frame[pos]=req_page[i];
                st[pos]=1;
            }
        }
    }
    cout<<endl<<"OPTIMAL_LFU:-"<<endl;
    cout<<"No. of Page Faults="<<page_fault<<endl;
    cout<<"Pages For Which Page Fault Occurs:-"<<endl;
    for(int i=0;i<page.size();i++)
        cout<<page[i]<<" ";
    cout<<endl;
}
void lru(int p,int f,int st[],vector<int> &req_page,int frame[])
{
    int page_fault=0,pos_replaced=0;
    vector<int> page;
    for(int i=0;i<req_page.size();i++)
    {
        int pos=find_page_frame(f,st,frame,req_page[i]);
        if(pos==false)//Page Fault Apply FIFO Page Replacement Algorithm
        {
            page_fault++;
            page.push_back(req_page[i]);
            if(pos_replaced<f)//Frames are Vacant
            {
                frame[pos_replaced]=req_page[i];
                st[pos_replaced]=1;
                pos_replaced++;
            }
            else//Frames are Full Vacant them by using LFU
            {
                for(int j=0;j<f;j++)
                    cout<<frame[j]<<" ";
                cout<<endl;
                int frame_st[f];
                for(int j=0;j<f;j++)
                    frame_st[j]=-1;
                int max=0;
                for(int j=i-1;j>=0;j--)
                {
                    for(int x=0;x<f;x++)
                    {
                        if(frame[x]==req_page[j] && frame[x]==-1)
                        {
                            frame_st[x]=max;
                            max++;
                        }
                    }
                }
                int pos=getid(f,frame_st);
                frame[pos]=req_page[i];
                st[pos]=1;
            }
        }
    }
    cout<<endl<<"LRU:-"<<endl;
    cout<<"No. of Page Faults="<<page_fault<<endl;
    cout<<"Pages For Which Page Fault Occurs:-"<<endl;
    for(int i=0;i<page.size();i++)
        cout<<page[i]<<" ";
    cout<<endl;
}
int main()
{
    cout<<"Enter Number of Pages of Process & Frames in Memory:-"<<endl;
    int p,f;
    cin>>p>>f;
    int st[f],frame[f];
    cout<<"Enter Number of Requests:-"<<endl;
    int req;
    cin>>req;
    vector<int> req_page;
    cout<<"Enter the Page Needed in Range[0,p-1] :-"<<endl;
    for(int i=0;i<req;i++)
    {
        int x;
        cin>>x;
        req_page.push_back(x);
    }
    for(int i=0;i<f;i++)//All Frames are Empty at Beginning
        st[i]=frame[i]=-1;
    fifo(p,f,st,req_page,frame);
    for(int i=0;i<f;i++)//All Frames are Empty at Beginning
        st[i]=frame[i]=-1;
    //optimal_lfu(p,f,st,req_page,frame);
    lru(p,f,st,req_page,frame);
    return 0;
}
/*
Test case
# of Page of Process=9
# of Frames=4
Page Request:-
5 5 4 5 3 5 7 4 5 7 8 6 7 4 1 4 3 6 1 7
*/

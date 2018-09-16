#include<bits/stdc++.h>
using namespace std;
pair<int,int> search(vector<int> a[],int rlow,int rhigh,int clow,int chigh,int key)
{
    cout<<rlow<<" "<<rhigh<<" "<<clow<<" "<<chigh<<endl;
    if(rlow==rhigh && clow==chigh)//Only one Element
    {
        if(a[rlow][clow]==key)
            return pair<int,int>(make_pair(rlow,clow));
        return pair<int,int>(make_pair(-1,-1));
    }
    if(rlow<rhigh && clow<chigh)
    {
        int rmid=(rlow+rhigh)/2;
        int cmid=(clow+chigh)/2;
        if(a[rmid][cmid]==key)
            return pair<int,int>(make_pair(rmid,cmid));
        else if(a[rmid][cmid]<key)//1st Quadrant has all elements smaller than key, Search in 2,3,4
        {
            pair<int,int> p;
            p=search(a,rlow,rmid,cmid+1,chigh,key);//Search in 2nd Quadrant
            if(p.first==-1 && p.second==-1)//Not Found in 2nd Quadrant
            {
                p=search(a,rmid+1,rhigh,clow,cmid,key);//Search in 3rd Quadrant
                if(p.first==-1 && p.second==-1)//Not Found in 2 & 3rd Quadrant
                    p=search(a,rmid+1,rhigh,cmid+1,chigh,key);//Search in 4th Quadrant
            }
            return p;
        }
        else//a[rmid][rmid]>key 4th Quadrant has all Elements Greater than key, Search in 1,2,3
        {
            pair<int,int> p;
            p=search(a,rlow,rmid,clow,cmid,key);//Search in 1st Quadrant
            if(p.first==-1 && p.second==-1)//Not Found in 1nd Quadrant
            {
                p=search(a,rlow,rmid,cmid+1,chigh,key);//Search in 2nd Quadrant
                if(p.first==-1 && p.second==-1)//Not Found in 1 & 2rd Quadrant
                    p=search(a,rmid+1,rhigh,clow,cmid,key);//Search in 3rd Quadrant
            }
            return p;
        }

    }
    return pair<int,int>(make_pair(-1,-1));
}
int main()
{
    cout<<"Enter the Number of Rows & Columns of Matrix:-"<<endl;
    int r,c;
    cin>>r>>c;
    cout<<"Enter the Elements in the Matrix:-"<<endl;
    vector<int> a[r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    cout<<"Enter the Elements to Found:-"<<endl;
    int key;
    cin>>key;
    cout<<"Sub Matrix{rlow,rhigh,clow,chigh}:-"<<endl;
    pair<int,int> p=search(a,0,r-1,0,c-1,key);
    if(p.first!=-1 && p.second!=-1)//Found
        cout<<"Found at Row="<<p.first<<" "<<"Column="<<p.second<<endl;
    else
        cout<<"Not Found"<<endl;
    return 0;
}
/* Test Cases
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
*/

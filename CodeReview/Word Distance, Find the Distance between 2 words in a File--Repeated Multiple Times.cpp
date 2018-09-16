#include<bits/stdc++.h>
using namespace std;
struct node
{
    string s;
    struct location *loc=NULL;
    struct node *next=NULL;
};
struct location
{
    int x;
    struct location *locnext=NULL;
};
int main()
{
    cout<<"Enter the File:-"<<endl;
    string file;
    getline(cin,file);
    cout<<"Enter the Words:-"<<endl;
    string word1,word2;
    cin>>word1>>word2;
    int w1=-1,w2=-1;
    int wordcount=0;
    struct node *h[10];
    for(int i=0;i<10;i++)
        h[i]=NULL;
    for(int i=0;i<file.size();)
    {
        int j=i;
        int sum=0;
        string temp;
        while(j<file.size() && file[j]!=' ')
        {
            temp.push_back(file[j]);
            sum+=file[j];
            j++;
        }
        sum=sum%10;
        cout<<temp<<" "<<sum<<endl;
        if(h[sum]==NULL)
        {
            struct node *p=(struct node *)malloc(sizeof(struct node));
            p->s=temp;
            p->loc=NULL;
            p->next=NULL;
            struct location *ploc=(struct location *)malloc(sizeof(struct location));
            ploc->x=wordcount;
            ploc->locnext=NULL;
            p->loc=ploc;
            h[sum]=p;
        }
        else
        {
           struct node *ptr=h[sum],*ptrp=h[sum];
           while(ptr!=NULL && ptr->s.compare(temp)!=0)
           {
               ptrp=ptr;
               ptr=ptr->next;
           }
           if(ptr==NULL )//First Time
           {
                struct node *p=(struct node *)malloc(sizeof(struct node));
                p->s=temp;
                p->loc=NULL;
                p->next=NULL;
                /*struct location *ploc=(struct location *)malloc(sizeof(struct location));
                ploc->x=wordcount;
                ploc->locnext=NULL;
                p->loc=ploc;*/
                ptrp->next=p;
           }
           else//Already Exists
           {
                struct location *ploc=(struct location *)malloc(sizeof(struct location));
                ploc->x=wordcount;
                ploc->locnext=NULL;
                struct location *ptrtemp=ptr->loc;
                while(ptrtemp->locnext!=NULL)
                    ptrtemp=ptrtemp->locnext;
                ptrtemp->locnext=ploc;
           }
        }
        i=j+1;
        wordcount++;
    }
    /*for(int i=0;i<10;i++)
    {
        struct node *p=h[i];
        while(p!=NULL)
        {
            cout<<p->s<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    int hash1=0,hash2=0;
    for(int i=0;i<word1.size();i++)
        hash1+=word1[i];
    hash1=hash1%10;
    for(int i=0;i<word2.size();i++)
        hash2+=word2[i];
    hash2=hash2%10;
    struct node *ptrav=h[hash1],*qtrav=h[hash2];
    while(ptrav->s.compare(word1)!=0)
        ptrav=ptrav->next;
    while(qtrav->s.compare(word2)!=0)
        qtrav=qtrav->next;
    vector<int> v1,v2;
    struct location *pp=ptrav->loc,*qq=qtrav->loc;
    while(pp!=NULL)
    {
        v1.push_back(pp->x);
        pp=pp->locnext;
    }
    while(qq!=NULL)
    {
        v2.push_back(qq->x);
        qq=qq->locnext;
    }
    int distance=INT_MAX;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(distance>abs(v1[i]-v2[j]))
            distance=abs(v1[i]-v2[j]);
        if(v1[i]>v2[j])
            j++;
        else
            i++;
    }
    cout<<"Minimum Distance="<<distance<<endl;*/
    return 0;
}
/*
you have a large text file contains word given any two words find the smallest distance between them if the operation is repeated many number of times handle it
*/


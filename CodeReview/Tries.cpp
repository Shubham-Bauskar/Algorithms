#include<bits/stdc++.h>
using namespace std;
struct node
{
    struct node *ch[26];
    int flag=0;
}*root=NULL;
bool find_trie(struct node *p,string a)
{
    if(p==NULL)
        return false;
    struct node *ptr=root;
    int i=0;
    while(ptr!=NULL && i<a.size())
    {
        ptr=ptr->ch[a[i]-97];
        i++;
    }
    if(ptr==NULL && i<a.size())
        return false;
    return true;
}
void addtotrie(string s)
{
    if(root==NULL)
    {
        root=(struct node *)malloc(sizeof(struct node));
        for(int i=0;i<26;i++)
            root->ch[i]=NULL;
    }
    struct node *ptr=root,*prev=root;
    int i=0;
    while(ptr!=NULL)
    {
        prev=ptr;
        ptr=ptr->ch[s[i]-97];
        i++;
    }
    //now from i-th index start filling
    while(i<s.size())
    {
        prev->ch[s[i]-97]=(struct node *)malloc(sizeof(struct node));
        prev=prev->ch[s[i]-97];
        for(int t=0;t<26;t++)
             prev->ch[t]=NULL;
        i++;
    }
}
int main()
{
    cout<<"Enter the Number of Strings:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Strings:-"<<endl;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        addtotrie(s);
    }
    cout<<"Enter String to Find:-"<<endl;
    string a;
    cin>>a;
    cout<<"Status="<<find_trie(root,a);
    return 0;
}

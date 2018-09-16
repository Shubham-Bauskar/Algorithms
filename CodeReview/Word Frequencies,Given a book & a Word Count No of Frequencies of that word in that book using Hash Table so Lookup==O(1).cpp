#include<bits/stdc++.h>
using namespace std;
struct node
{
    string word;
    int count=0;
    struct node *next;
};
int main()
{
    cout<<"Enter the Book:-"<<endl;
    string book;
    getline(cin,book);
    struct node *hash[3];
    for(int i=0;i<3;i++)
        hash[i]=NULL;

    for(int i=0;i<book.size();)
    {
        int j=i;
        string temp;
        int hash_val=0;
        while(j<book.size() && book[j]!=' ')
        {
            temp.push_back(book[j]);
            hash_val+=book[j]-97;
            j++;
        }
        i=j+1;//j is pointing at the whitespace
        hash_val=hash_val%3;
        cout<<temp<<" "<<hash_val<<endl;
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->word=temp;
        p->count=1;
        p->next=NULL;
        if(hash[hash_val]==NULL)//First time inserting in that table
            hash[hash_val]=p;
        else//Check if the Word Already Exits if Yes then increase the count if not then add at the end
        {
            int flag=0;
            struct node *ptr1=hash[hash_val],*ptr=hash[hash_val];
            while(ptr1!=NULL)
            {
                if(temp.compare(ptr1->word)==0)//Already Exists
                {
                    flag=1;
                    break;
                }
                ptr=ptr1;
                ptr1=ptr1->next;
            }
            if(flag==1)//Increase the Count of that word b/c that word is already present
                ptr1->count=ptr1->count + 1;
            else//Add the new node at the back of the list b/c this word is not present
                ptr->next=p;
            cout<<"2\n";
        }
        cout<<"Hash"<<endl;
        cout<<"3\n";
        for(int t=0;t<3;t++)
        {
            cout<<t<<"-";
            struct node *pq=hash[t];
            while(pq!=NULL)
            {
                cout<<pq->word<<" ";
                pq=pq->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
//Test Case:- we want an example with some names with multiple value and some with none

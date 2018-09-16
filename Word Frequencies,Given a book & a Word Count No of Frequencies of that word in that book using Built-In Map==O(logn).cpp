#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the Book:-"<<endl;
    string book;
    getline(cin,book);
    map<string,int> v;
    for(int i=0;i<book.size();)
    {
        int j=i;
        string temp;
        while(j<book.size() && book[j]!=' ')
        {
            temp.push_back(book[j]);
            j++;
        }
        if(v.find(temp)!=v.end())//This Word is Already Present
        {
            map<string,int>::iterator p;
            p=v.find(temp);
            p->second=p->second + 1;
        }
        else
            v.insert(pair<string,int>(temp,1));
        i=j+1;//j is pointing at the whitespace
    }
    cout<<"Hash Map:-"<<endl;
    map<string,int>::iterator p;
    for(p=v.begin();p!=v.end();p++)
        cout<<p->first<<" "<<p->second<<endl;;
    return 0;
}
//Test Case:- we want an example with some names with multiple value and some with none


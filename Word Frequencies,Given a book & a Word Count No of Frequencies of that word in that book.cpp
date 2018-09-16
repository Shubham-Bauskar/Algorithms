#include<bits/stdc++.h>
using namespace std;
int count_freq(string book,string word)
{
    int count=0;
    for(int i=0;i<=book.size()-word.size();i++)
    {
        if(book[i]==word[0])//First Character Matches
        {
            int flag=1;
            for(int j=i;j<i+word.size();j++)
            {
                if(book[j]!=word[j-i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                count++;
        }
    }
    return count;
}
int main()
{
    cout<<"Enter the Book:-"<<endl;
    string book,word;
    getline(cin,book);
    cout<<"Enter the Word to be Searched:-"<<endl;
    cin>>ws>>word;
    cout<<"Frequency="<<count_freq(book,word);
    return 0;
}

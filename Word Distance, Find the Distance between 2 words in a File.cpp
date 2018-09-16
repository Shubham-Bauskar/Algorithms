#include<bits/stdc++.h>
using namespace std;
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
    for(int i=0;i<file.size();)
    {
        int j=i;
        string temp;
        while(j<file.size() && file[j]!=' ')
        {
            temp.push_back(file[j]);
            j++;
        }
        if(temp.compare(word1)==0)
        {
            if(w1==-1)//First time Encounter
                w1=wordcount;
            else if(w2==-1)//Since 2nd word is not encountered yet so this will minimize the distance
                w1=wordcount;
            else//Compare the distance if we get minimum distance the update else ignore
            {
                if(abs(w1-w2)>abs(w2-wordcount))//update
                    w1=wordcount;
           }
        }
        else if(temp.compare(word2)==0)
        {
            if(w2==-1)//First time Encounter
                w2=wordcount;
            else if(w1==-1)//Since 1st word is not encountered yet so this will minimize the distance
                w2=wordcount;
            else//Compare the distance if we get minimum distance the update else ignore
            {
                if(abs(w1-w2)>abs(w1-wordcount))//update
                    w2=wordcount;
            }
        }
        i=j+1;
        wordcount++;
    }
    cout<<"Minimum Distance="<<abs(w1-w2)-1<<endl;
    return 0;
}
/*
you have a large text file contains word given any two words find the smallest distance between them if the operation is repeated many number of times handle it
*/

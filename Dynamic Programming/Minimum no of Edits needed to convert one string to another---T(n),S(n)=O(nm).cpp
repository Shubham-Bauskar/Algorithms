#include<bits/stdc++.h>
using namespace std;
int min_val(int a,int b,int c)
{
    if(a<=b && a<=c)
        return a;
    if(b<=a && b<=c)
        return b;
    return c;
}
void minimum_no_edits(string a,string b)
{
    int lookup[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++)//if string b is empty
        lookup[i][0]=i;
    for(int j=0;j<=b.size();j++)//if string a is empty
        lookup[0][j]=j;
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[i]==b[j])//don't change these characters + whatever we have done to change a[0..(i-1)] to b[0..(j-1)]
                lookup[i][j]=lookup[i-1][j-1];
            else if(a[i]!=b[j])
            {
                lookup[i][j]=1+min_val(lookup[i-1][j-1],lookup[i][j-1],lookup[i-1][j]);
                //Replace a[i]-->b[j] or vice-versa=1 edit + convert a[0,i-1] to b[0,j-1]
                //Delete a[i]=1 edit + convert a[0,i-1] to b[0,j]
                //Delete b[j]=1 edit + convert a[0,i] to b[0,j-1]
            }
        }
    }
    cout<<"Minimum No. of Edits="<<lookup[a.size()][b.size()]<<endl;
    cout<<"Operations:-"<<endl;
    int i=a.size(),j=b.size();
    while(i>0 && j>0)
    {
        int top=lookup[i-1][j];
        int diag=lookup[i-1][j-1];
        int left=lookup[i][j-1];
        if(a[i]==b[j] && diag==lookup[i][j])//Same characters so no change
        {
            i--;
            j--;
        }//Different Characters
        else if(a[i]!=b[j] && diag+1==lookup[i][j])//Replace a[i]<-->b[j]
        {
            cout<<"Replace:"<<a[i]<<"-->"<<b[j]<<endl;
            i--;
            j--;
        }
        else if(a[i]!=b[j] && left+1==lookup[i][j])//Delete b[j] i.e we came from left
        {
            cout<<"Delete_b:"<<b[j]<<endl;
            j--;
        }
        else if(a[i]!=b[j] && top+1==lookup[i][j])//Delete a[i] i.e we came from top
        {
            cout<<"Delete_a:"<<a[i]<<endl;
            i--;
        }
    }
}
int main()
{
    cout<<"Enter both the Strings;-"<<endl;
    string a,b;
    cin>>a>>ws>>b;
    minimum_no_edits(a,b);
    return 0;
}

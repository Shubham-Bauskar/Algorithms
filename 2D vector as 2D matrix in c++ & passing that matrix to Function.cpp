#include<bits/stdc++.h>
using namespace std;
void printmatrix(vector<vector<int> > &a)
{
    cout<<"MATRIX:-"<<endl;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
    cout<<"Enter the value of n:-"<<endl;
    int n;
    cin>>n;
    vector<vector<int> >v;
    cout<<"Enter the Elements in the Matrix:-"<<endl;
    for(int i=0;i<n;i++)
	{
		vector<int> temp;
        for(int j=0;j<n;j++)
        {
			int x;
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
    printmatrix(v);
    return 0;
}



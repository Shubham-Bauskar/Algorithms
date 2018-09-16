#include<bits/stdc++.h>
using namespace std;
int finddigit(int x,int p)
{
	int temp=0;
	while(p--)
	{
		temp=x%10;
		x=x/10;
	}
	return temp;
}
void radixsort(int a[],int n,int d)
{
    vector<int> v[10];//Since Each Digit is in Range [0-9] so sort according to digits from LSD to MSD.
    for(int p=1;p<=d;p++)//No of Passes=No of Digits in an Element.
    {
        for(int i=0;i<n;i++)//Repeatedly travese array & sort the element on the basis of the digit at position=p
        {					//1=LSD
            int pos=finddigit(a[i],p);
            v[pos].push_back(a[i]);
        }
        int sp=0;
        for(int i=0;i<10;i++)
        {
			if(v[i].size()!=0)
			{
				sort(v[i].begin(),v[i].end());
				for(int j=0;j<v[i].size();j++)
					a[sp++]=v[i][j];
			}
        }
        for(int i=0;i<10;i++)
            v[i].clear();
    }
}
int numberofdigits(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	int t=0;
	while(max!=0)
	{
		t++;
		max=max/10;
	}
	return t;
}
int main()
{
    cout<<"Enter the Number of Elements in Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int d=numberofdigits(a,n);
    radixsort(a,n,d);
	cout<<"Radix Sort:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

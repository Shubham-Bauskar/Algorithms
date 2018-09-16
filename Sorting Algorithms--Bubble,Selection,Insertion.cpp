#include<bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)//Run Sorting Algorithm (n-1) time because at (n-1)th iteration 2nd Smallest Element
    {                     //is at its right Place, so automatically smallest element is at its 1st place
        int flag=1;
        for(int j=0;j<n-1-i;j++)
        {// No need to swap till last only swap till (n-i-2)th index.
            if(a[j]>a[j+1])//Swap
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
            }
        }
        if(flag==1)
            break;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void selectionsort(int a[],int n)
{//*** Not a STABLE ALGORITHM ***
    for(int i=0;i<n-1;i++)//Run Sorting Algorithm (n-1) time because at (n-1)th iteration 2nd Largest Element
    {//is at its right Place, so automatically Largest element is at its (n-1)th index.
        int min=a[i],mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
               min=a[j];
               mini=j;
            }
        }
        //Swap minimum element of that iteration with ith element
        int temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void insertionsort(int a[],int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        j=i-1;
        while(a[j]>a[i] && j>=0)
            j--;
        int sp=j+1;
        for(j=i;j>sp;j--)
            a[j]=a[j-1];
        a[sp]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    cout<<"Enter the Size of the Array:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Elements in the Array:-"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Bubble Sort:-"<<endl;
    bubblesort(a,n);
    cout<<"Selection Sort:-"<<endl;
    selectionsort(a,n);
    cout<<"Insertion Sort:-"<<endl;
    insertionsort(a,n);
    return 0;
}

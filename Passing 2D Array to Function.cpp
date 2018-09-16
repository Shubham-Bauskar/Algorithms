#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void fun(int *arr,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cout<<*(arr+i*c+j)<<" ";
        cout<<"\n";
    }
}
int main()
{
    int b[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // fun(Address of 1st element i.e b[0][0],No of Rows,No of Columns)
    fun(&b[0][0],3,4);
    // Dynamically Allocating 2D Array
    int r,c;
    cin>>r>>c;
    int *a[r];
    for(int i=0;i<r;i++)
        a[i]=(int *)malloc(c*sizeof(int));
    for(int i=0;i<r;i++)
        for(int j=0;j<r;j++)
            cin>>a[i][j];
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int eggs_drop_floors(int eggs,int floor)
{
   if(floor==0 || floor==1)
    return floor;
   if(eggs==1)
    return floor;
   int min=INT_MAX;
   for(int f=1;f<=floor;f++)
   {
       int x=1+max(eggs_drop_floors(eggs-1,f-1),eggs_drop_floors(eggs,floor-f));
       if(x<min)
        min=x;
   }
   return min;
}
int main()
{
    cout<<"Enter the Number of Floors:-"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Number of Eggs:-"<<endl;
    int m;
    cin>>m;
    cout<<"Minimum No. of Attempts Needed to Find="<<eggs_drop_floors(m,n);
    return 0;
}


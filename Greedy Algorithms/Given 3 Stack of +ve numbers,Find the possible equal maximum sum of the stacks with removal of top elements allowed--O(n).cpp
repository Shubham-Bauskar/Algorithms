#include<bits/stdc++.h>
using namespace std;
int find_max(int a,int b,int c)
{
    if(a>b && a>c)
        return 1;
    if(b>a && b>c)
        return 2;
    return 3;
}
int main()
{
    cout<<"Enter the Number of Elements in 3 Stacks:-"<<endl;
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int st1[n1],st2[n2],st3[n3],top1=n1-1,top2=n2-1,top3=n3-1;
    int sum1=0,sum2=0,sum3=0;
    cout<<"Enter the Element in Stack1:-"<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>st1[i];
        sum1+=st1[i];
    }
    cout<<"Enter the Element in Stack2:-"<<endl;
    for(int i=0;i<n2;i++)
    {
        cin>>st2[i];
        sum2+=st2[i];
    }
    cout<<"Enter the Element in Stack3:-"<<endl;
    for(int i=0;i<n3;i++)
    {
        cin>>st3[i];
        sum3+=st3[i];
    }
    while(1)
    {
        if(sum1==sum2 && sum2==sum3)
        {
            cout<<"Maximum Possible Sum="<<sum1<<endl;
            break;
        }
        else if(top1==-1 || top2==-1 || top3==-1)
        {
            cout<<"Not Possible"<<endl;
            break;
        }
        else
        {
            int pos=find_max(sum1,sum2,sum3);
            if(pos==1)//Remove Element from stack1
            {
                sum1-=st1[top1];
                top1--;
            }
            else if(pos==2)//Remove Element from stack2
            {
                sum2-=st2[top2];
                top2--;
            }
            else//Remove Element from stack3
            {
                sum3-=st3[top3];
                top3--;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1){
    int n;
    char d;
    cin>>n>>ws>>d;
    int x,y;
    cin>>x>>y;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          a[i][j]=0;
    char dir=d;
    if(d=='n' && x==0 && y==0)
    {
        int t=1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[i][j]=t;
            }
        }
    }
    else if(d=='n' && x==0 && y==n-1)
    {
        int t=1;
        for(int i=0;i<n;i++)
        {
            if(i%2!=0)
            {
                for(int j=0;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[i][j]=t;
            }
        }

    }
    else if(d=='e' && x==0 && y==n-1)//error
    {
        int t=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2!=0)
            {
                for(int j=0;j<n;j++,t++)
                    a[j][i]=t;
            }
            else
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[j][i]=t;
            }
        }
        /*for(int i=0;i<n/2;i++)
        {
            int temp[n];
            for(int j=0;j<n;j++)
                temp[j]=a[i][j];
            for(int j=0;j<n;j++)
                a[i][j]=a[n-1-i][j];
            for(int j=0;j<n;j++)
                a[n-1-i][j]=temp[j];
        }*/
    }
    else if(d=='e' && x==n-1 && y==n-1)
    {
        int t=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2==0)
            {
                for(int j=0;j<n;j++,t++)
                    a[j][i]=t;
            }
            else
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[j][i]=t;
            }
        }

    }
    else if(d=='w' && x==0 && y==0)
    {
        int t=1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<n;j++,t++)
                    a[j][i]=t;
            }
            else
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[j][i]=t;
            }
        }

    }
    else if(d=='w' && x==n-1 && y==0)
    {
        int t=1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[j][i]=t;
            }
            else
            {
                for(int j=0;j<n;j++,t++)
                    a[j][i]=t;
            }
        }

    }
    else if(d=='s' && x==n-1 && y==0)
    {
        int t=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2!=0)
            {
                for(int j=0;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[i][j]=t;
            }
        }
    }
    else if(d=='s' && x==n-1 && y==n-1)
    {
        int t=1;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2!=0)
            {
                for(int j=n-1;j>=0;j--,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=0;j<n;j++,t++)
                    a[i][j]=t;
            }
        }
    }
    else if(d=='n' && x==n-1 && y==0)
    {
        int t=1;
        for(int i=n-1;i>=0;i--,t++)
            a[i][0]=t;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=1;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=1;j--,t++)
                    a[i][j]=t;
            }
        }
    }
    else if(d=='n' && x==n-1 && y==n-1)
    {
        int t=1;
        for(int i=n-1;i>=0;i--,t++)
            a[i][0]=t;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=1;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=1;j--,t++)
                    a[i][j]=t;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int temp=a[i][j];
                a[i][j]=a[i][n-1-j];
                a[i][n-1-j]=temp;
            }
        }
    }
    else if(d=='s' && x==0 && y==0)
    {
        int t=1;
        for(int i=0;i<n;i++,t++)
            a[i][0]=t;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2!=0)
            {
                for(int j=1;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=1;j--,t++)
                    a[i][j]=t;
            }
        }
    }
    else if(d=='s' && x==0 && y==n-1)
    {
        int t=1;
        for(int i=0;i<n;i++,t++)
            a[i][0]=t;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2!=0)
            {
                for(int j=1;j<n;j++,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int j=n-1;j>=1;j--,t++)
                    a[i][j]=t;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int temp=a[i][j];
                a[i][j]=a[i][n-1-j];
                a[i][n-1-j]=temp;
            }
        }
    }
    else if(d=='e' && x==n-1 && y==0)
    {
        int t=1;
        for(int i=0;i<n;i++,t++)
            a[n-1][i]=t;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2==0)
            {
                for(int j=0;j<n-1;j++,t++)
                    a[j][i]=t;
            }
            else
            {
                for(int j=n-2;j>=0;j--,t++)
                    a[j][i]=t;
            }
        }
    }
    else if(d=='e' && x==0 && y==0)
    {
        int t=1;
        for(int i=0;i<n;i++,t++)
            a[n-1][i]=t;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2==0)
            {
                for(int j=0;j<n-1;j++,t++)
                    a[j][i]=t;
            }
            else
            {
                for(int j=n-2;j>=0;j--,t++)
                    a[j][i]=t;
            }
        }
        for(int i=0;i<n/2;i++)
        {
            int temp[n];
            for(int j=0;j<n;j++)
                temp[j]=a[i][j];
            for(int j=0;j<n;j++)
                a[i][j]=a[n-1-i][j];
            for(int j=0;j<n;j++)
                a[n-1-i][j]=temp[j];
        }
    }
    else if(d=='w' && x==n-1 && y==n-1)
    {
        int t=1;
        for(int i=n-1;i>=0;i--,t++)
            a[n-1][i]=t;
        for(int j=0;j<n;j++)
        {
            if(j%2==0)
            {
                for(int i=n-2;i>=0;i--,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int i=0;i<n-1;i++,t++)
                    a[i][j]=t;
            }
        }
    }
    else if(d=='w' && x==0 && y==n-1)
    {
        int t=1;
        for(int i=n-1;i>=0;i--,t++)
            a[n-1][i]=t;
        for(int j=0;j<n;j++)
        {
            if(j%2==0)
            {
                for(int i=n-2;i>=0;i--,t++)
                    a[i][j]=t;
            }
            else
            {
                for(int i=0;i<n-1;i++,t++)
                    a[i][j]=t;
            }
        }
        for(int i=0;i<n/2;i++)
        {
            int temp[n];
            for(int j=0;j<n;j++)
                temp[j]=a[i][j];
            for(int j=0;j<n;j++)
                a[i][j]=a[n-1-i][j];
            for(int j=0;j<n;j++)
                a[n-1-i][j]=temp[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int Q[100];
int f=-1;
int rear=-1;
int count_visited_nodes=0;
int ts[100],top=-1;
int main()
{
    int n;
    printf("Enter Number of Projects:-\n");
    scanf("%d",&n);
    int m,i;
    printf("Enter the Number of Dependencies:-\n");
    scanf("%d",&m);
    printf("Enter the Dependencies in form of U-->>V:-\n");
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          a[i][j]=0;
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u][v]=1;
    }
    // Step 1:- Calculate in-degree of each vertex
    int indegree[n];
    for(int i=0;i<n;i++)
        indegree[i]=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(a[j][i]==1)
                c++;
        }
        indegree[i]=c;
    }
    cout<<"In-Degree of Vertex:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<indegree[i]<<" ";
    cout<<endl;
    // Step 2:- Find All vertex whose in-degree=0 & add them in Q
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            Q[++rear]=i;
            if(f==-1)
                f=0;
        }
    }
    // Step 3:- Remove an Element from Q increment c_visited_node && reduce the in-degree of its adjacent node by 1
    // if after reducing in-degree of any node become 0 then add it to Q
    // Repeat above process till Q is not empty

    while(f!=-1)
    {
        int x=Q[f++];
        ts[++top]=x;
        count_visited_nodes++;
        if(f==rear+1)//Last Element Deleted
            rear=f=-1;
        for(int i=0;i<n;i++)//Finding its adjacent node & decreasing their in-degree by 1
        {
            if(a[x][i]==1)
            {
                indegree[i]--;
                if(indegree[i]==0)//Add to Q
                {
                    Q[++rear]=i;
                    if(f==-1)
                        f=0;
                }
            }
        }
    }
    if(count_visited_nodes>=0)
    {
        cout<<"Topological Sort Exists:-"<<endl;
        for(int i=0;i<=top;i++)
            cout<<ts[i]<<" ";
    }
    else
        cout<<"Topological Sort Not Exists"<<endl;
	return 0;
}


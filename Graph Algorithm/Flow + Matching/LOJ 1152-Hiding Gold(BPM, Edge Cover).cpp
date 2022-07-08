#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 405


bool vis[sz];
int n, m, flow[sz][sz],cap[sz][sz],par[sz];
int fx[] = {+0,-0,-1,+1};
int fy[] = {-1,+1,+0,-0};
char grid[25][25];
int nodenum[25][25];

int BFS(int source,int destination)
{
    memset(vis,0,sizeof(vis));
    queue<int> q;
    vis[source] =  1;
    par[source] = -1;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0;v<=destination;v++)
        {
            if(!vis[v] && (cap[u][v]-flow[u][v])>0)
            {
                q.push(v);
                par[v] = u;
                vis[v] = 1;
            }
        }
    }
    return vis[destination];
}

int MxFlowFuN(int source,int destination)
{
    int u, v, MxFlow = 0;
    while(BFS(source,destination))
    {
        int mnpathflow = 1e9;
        for(v = destination; v != source; v = par[v])
        {
            u = par[v];
            mnpathflow = min(mnpathflow, cap[u][v]-flow[u][v]);
        }
        for(v = destination; v != source; v = par[v])
        {
            u = par[v];
            flow[u][v] += mnpathflow;
            flow[v][u] -= mnpathflow;
        }
        MxFlow += mnpathflow;
    }
    return MxFlow;
}

bool valid(int x,int y)
{
    return (x>=1 && x<=m && y>=1 && y<=n && grid[x][y]=='*');
}


void Solve(int t)
{
    memset(flow,0,sizeof(flow));
    memset(cap,0,sizeof(cap));
    memset(nodenum,0,sizeof(nodenum));

    int i,j,cur=1,totgold=0;
    scanf("%d %d",&m,&n);

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='*')
            {
                nodenum[i][j] = cur++;
                totgold++;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(grid[i][j]=='*' && (i+j)%2==0)
            {
                int u = nodenum[i][j];
                cap[0][u] = 1;
            }
            if(grid[i][j]=='*' && (i+j)%2==1)
            {
                int u = nodenum[i][j];
                cap[u][totgold+1] = 1;
            }
        }
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(grid[i][j]=='*')
            {
                for(int k=0;k<4;k++)
                {
                    int nx = i+fx[k],ny = j+fy[k];
                    if(valid(i+fx[k],j+fy[k]) && (i+j)%2==0)
                    {
                        int u = nodenum[i][j];
                        int v = nodenum[i+fx[k]][j+fy[k]];
                        cap[u][v]=1;
                    }
                }
            }
        }
    }

    int ans =  totgold- MxFlowFuN(0,totgold+1);
    printf("Case %d: %d\n",t,ans);

}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}


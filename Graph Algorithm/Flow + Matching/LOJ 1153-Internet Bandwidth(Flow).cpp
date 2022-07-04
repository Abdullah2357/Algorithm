#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 105

bool vis[sz];
int n, e, cap[sz][sz], flow[sz][sz], par[sz];

bool BFS(int source, int destination)
{
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    par[source] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=1;v<=n;v++)
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

void Solve(int t)
{
    int source, destination, i, j, u, v, c, ans;

    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
//    memset(par,-1,sizeof(par));

    scanf("%d",&n);
    scanf("%d %d %d",&source,&destination,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d %d %d",&u,&v,&c);
        cap[u][v] += c;
        cap[v][u] += c;
    }

    ans = MxFlowFuN(source, destination);
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


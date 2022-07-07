#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 105
bool vis[sz];
int n, w, flow[sz][sz],cap[sz][sz],par[sz],a[sz];

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

void Solve(int t)
{
    memset(flow,0,sizeof(flow));
    memset(cap,0,sizeof(cap));

    int i,j,c,u,v;
    scanf("%d %d",&n,&w);
    cap[1][1+n] = 1e9;
    cap[1+n][1] = 1e9;
    cap[n][n+n] = 1e9;
    cap[n+n][n] = 1e9;

    for(i=2;i<n;i++)
    {
        scanf("%d",&a[i]);
        cap[i][i+n] = a[i];
        cap[i+n][i] = 1e9;
    }

    for(i=1;i<=w;i++)
    {
        scanf("%d %d %d",&u,&v,&c);
        cap[u+n][v] = c;
        cap[v+n][u] = c;
    }

    int ans = MxFlowFuN(1,n+n);
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


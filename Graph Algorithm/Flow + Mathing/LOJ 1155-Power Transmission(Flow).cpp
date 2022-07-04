#include<bits/stdc++.h>
#define ll long long
using namespace std;

/**
1. int this problem we have to make a global source and a global sink.
2. to define the capacity of node, we have to split node.

**/
#define sz 205

bool vis[sz];
int n, e, cap[sz][sz], flow[sz][sz], par[sz], a[sz];

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
        for(int v=0;v<=n+1+n;v++)
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
    int source, destination, i, j, u, v, c, ans, B, D;

    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
//    memset(par,-1,sizeof(par));

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        int ain = i;
        int aout = i+n;
        cap[ain][aout] += a[i];
    }

    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d %d %d",&u,&v,&c);
        int uout = u+n;
        int vin = v;
        cap[uout][vin] += c;
    }

    scanf("%d %d",&B,&D);
    for(i=1;i<=B;i++)
    {
        scanf("%d",&u);
        cap[0][u]+=1e9;///super source
    }
    for(i=1;i<=D;i++)
    {
        scanf("%d",&u);
        int uout = u+n;
        cap[uout][2*n+1]+=1e9;///2*n+1 super sink
    }

    ans = MxFlowFuN(0, 2*n+1);
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

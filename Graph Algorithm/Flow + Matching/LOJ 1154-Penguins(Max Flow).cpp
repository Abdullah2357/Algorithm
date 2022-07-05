#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 205

bool vis[sz];
int n, cap[sz][sz], flow[sz][sz], par[sz], x[sz],y[sz],nop[sz],m[sz];
vector<int> graph[sz];

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
        for(auto v:graph[u])
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

void Clean(int n)
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j=i;j<=n+1;j++)
        {
            flow[i][j] = 0;
            flow[j][i] = 0;
            cap[i][j] = 0;
            cap[j][i] = 0;
        }
        graph[i].clear();
    }
}

void addEdge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int  sq(int value)
{
    return (value*value);
}

void Solve(int t)
{
    int source, destination, i, j, ans,totpenguin = 0;


    scanf("%d",&n);
    double d;
    scanf("%lf",&d);

    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&x[i],&y[i],&nop[i],&m[i]);
        totpenguin += nop[i];
    }

    for(i=1;i<=n;i++)
    {
        if(nop[i]>0)
        {
            addEdge(0,i);
        cap[0][i] = nop[i];
        }
        addEdge(i,n+i);
        cap[i][i+n] = m[i];
    }

    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            double dis = sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
            if(dis<=d)
            {
                cap[i+n][j] = 1e9;
                cap[j+n][i] = 1e9;
                addEdge(i+n,j);
                addEdge(j+n,i);
            }
        }
    }



    bool fg=0;
    printf("Case %d:",t);

    for(i=1;i<=n;i++){
        memset(flow,0,sizeof(flow));
        cap[i][n+i] = 1e9;
        cap[i+n][2*n+1] = 1e9;
        addEdge(i+n,2*n+1);

        ans = MxFlowFuN(0,2*n+1);

        if(ans>=totpenguin)
        {
            printf(" %d",i-1);
            fg=1;
        }

        cap[i][i+n] = m[i];
        cap[i+n][2*n+1] = 0;
    }


    if(!fg)
    {
        printf(" -1");

    }
    printf("\n");
    Clean(2*n+1);

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


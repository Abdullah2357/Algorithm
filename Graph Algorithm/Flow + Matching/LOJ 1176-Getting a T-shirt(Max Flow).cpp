#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 205
map<string,int> tshirt;
bool vis[sz];
int n, m, flow[sz][sz],cap[sz][sz],par[sz];

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
        for(int v=0;v<=m+13;v++)
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

    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        string s,s2;
        cin>>s>>s2;
        cap[i+12][tshirt[s]] = 1e9;
//        cap[tshirt[s]][i+12] = 1e9;
        cap[i+12][tshirt[s2]] = 1e9;
//        cap[tshirt[s2]][i+12] = 1e9;
        cap[0][i+12] = 1;/// connect with global source
    }
    for(i=1;i<=6;i++)
    {
        cap[i][i+6] = n; /// node capacity(no of tshirt)
        cap[i+6][m+12+1] = 1e9;/// connect with global sink
    }


    int ans = MxFlowFuN(0,m+13);
    if(ans>=m)
        printf("Case %d: YES\n",t);
    else
        printf("Case %d: NO\n",t);

}
int main()
{
    int t,T;
    tshirt["S"] = 1;
    tshirt["M"] = 2;
    tshirt["L"] = 3;
    tshirt["XL"] = 4;
    tshirt["XXL"] = 5;
    tshirt["XS"] = 6;

    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}


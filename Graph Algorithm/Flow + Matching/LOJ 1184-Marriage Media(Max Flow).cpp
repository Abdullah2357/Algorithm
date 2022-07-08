#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 105


bool vis[sz];
int n, m, flow[sz][sz],cap[sz][sz],par[sz];
int manheight[sz],manage[sz],manstatus[sz],womanheight[sz],womanage[sz],womanstatus[sz];

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

    int u,v,i,j;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&manheight[i],&manage[i],&manstatus[i]);
        cap[0][i] = 1;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&womanheight[i],&womanage[i],&womanstatus[i]);
        cap[i+m][n+m+1] = 1;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(abs(manheight[i]-womanheight[j])<=12 && abs(manage[i]-womanage[j])<=5 && manstatus[i]==womanstatus[j])
            {
                cap[i][j+m] = 1;
            }
        }
    }

    int ans =  MxFlowFuN(0,n+m+1);
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


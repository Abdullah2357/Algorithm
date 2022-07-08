#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 2505


bool vis[sz];
int n, m, flow[sz][sz],cap[sz][sz],par[sz];
int fx[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int fy[] = {+2,-2,+1,-1,+2,-2,-1,+1};
int nodenum[205][205];



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
    memset(nodenum,0,sizeof(nodenum));

    map<pair<int,int>,int> broken;
    int i,j,cur=1,k,white=0,black=0,x,y;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d",&x,&y);
        broken[{x,y}] = 1;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((i+j)%2==0 && !broken[{i,j}])
            {
                nodenum[i][j] = cur++;
                white++;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((i+j)%2==1 && !broken[{i,j}])
            {
                nodenum[i][j] = cur++;
                black++;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((i+j)%2 || broken[{i,j}])
                continue;
            for(int k=0;k<8;k++)
            {
                int nx = i+fx[k],ny = j+fy[k];
                if(nx>0 && nx<=m && ny>0 && ny<=n && !broken[{nx,ny}])
                {
                    cap[nodenum[i][j]][nodenum[nx][ny]] = 1;
                }
            }
        }
    }

    for(i=1;i<=white;i++)
        cap[0][i] = 1;
    for(i=white+1;i<=white+black;i++)
        cap[i][white+black+1] = 1;

    int ans =  (black+white)- MxFlowFuN(0,white+black+1);
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



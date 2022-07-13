
#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 20005

bool vis[sz];
int n, m, par[sz],nodeno[105][105],source,sink;
char grid[105][105];

int fx[] = {0,0,+1,-1};
int fy[] = {-1,+1,0,0};

struct Edge{
    int u,v,cap;
    Edge(int _u,int _v,int _cap)
    {
        u = _u;
        v = _v;
        cap = _cap;
    }
};
vector<Edge> edges;
vector<int> edgeid[sz];
void Clean()
{
    for(int i=0;i<sz;i++)
        edgeid[i].clear();
    edges.clear();
}

void addEdge(int u, int v, int w)
{
    edges.push_back(Edge(u,v,w));
    edges.push_back(Edge(v,u,0));

    edgeid[u].push_back(edges.size()-2);
    edgeid[v].push_back(edges.size()-1);
}

int DFS(int u, int flow=1e9)
{
    vis[u] = 1;
    if(u==sink)
        return flow;
    int ret = 0;
    for(int i=0;i<edgeid[u].size();i++){
        int id = edgeid[u][i];
        Edge &e = edges[id];
        if(!e.cap || vis[e.v])
            continue;
        ret = DFS(e.v, min(flow,e.cap));

        if(ret)
        {
            Edge &rev = edges[id^1];
            e.cap -= ret;
            rev.cap += ret;
            return ret;
        }
    }
    return ret;
}


int FordFulkerson()
{
    int MxFlow = 0;
    while(1)
    {
        memset(vis,0,sizeof(vis));
        int mnpathflow = DFS(source);
        if(mnpathflow==0)
            break;
        MxFlow += mnpathflow;
    }

    return MxFlow;
}

void Solve(int t)
{
    int i, j, ans, person=0,cur=1;

    Clean();
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>grid[i][j];
            nodeno[i][j] = cur++;
            if(grid[i][j]=='*')
                person++;
        }
    }
    source = 0, sink = 2*n*m+1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            addEdge(nodeno[i][j],nodeno[i][j]+(n*m),1);///node split
            if(grid[i][j]=='*')
                addEdge(source,nodeno[i][j],1);/// connect global source
            if(i==1||i==n || j==1||j==m)
            {
                addEdge(nodeno[i][j]+(n*m),sink,1);///connect global sink
            }
            else{
                for(int k=0;k<4;k++)
                {
                    int nx = i+fx[k];
                    int ny = j+fy[k];
                    if(nx>0 && nx<=n && ny>0 && ny<=m && grid[nx][ny]!='*')
                    {
                        addEdge(nodeno[i][j]+(n*m),nodeno[nx][ny],1);
                    }
                }
            }
        }
    }
    ans = FordFulkerson();
    if(person==ans)
        printf("Case %d: yes\n",t);
    else
        printf("Case %d: no\n",t);

}


int main()
{
    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}



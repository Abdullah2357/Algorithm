#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 105
bool vis[sz];
map<pair<int,int>,int> m;
int n, flow[sz][sz],cap[sz][sz],par[sz];
char grid[sz][sz],cur;

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
        for(int v=0;v<=cur;v++)
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
bool vis2[sz][sz];
int fx[] = {0,0,-1,1};
int fy[] = {-1,1,0,0};

bool valid(int x,int y)
{
    return (x>0 && x<=n && y>0 && y<=n && vis2[x][y]==0 && grid[x][y]!='#');
}
int level[28][28][28][28];

void FindDistance(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    memset(vis2,0,sizeof(vis2));
    vis2[x][y] = 1;
    level[x][y][x][y] = 0;
    while(!q.empty())
    {
        int nx = q.front().first, ny = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(valid(nx+fx[i],ny+fy[i]))
            {
                vis2[nx+fx[i]][ny+fy[i]] = 1;
                int p = m[{x,y}],qq = m[{nx+fx[i],ny+fy[i]}];
                level[x][y][nx+fx[i]][ny+fy[i]] = level[x][y][nx][ny]+1;
                q.push({nx+fx[i],ny+fy[i]});
            }
        }
    }

}
void Clean()
{
    for(int i=0;i<28;i++)
    {
        for(int j=0;j<28;j++)
        {
            for(int k=0;k<28;k++)
            {
                for(int l=0;l<28;l++)
                {
                    level[i][j][k][l] = 1e8;
                }
            }
        }
    }
}
void Solve(int t)
{
    Clean();

    int i,j,ghosts,human;
    cur=1;
    scanf("%d",&n);
    m.clear();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='G')
                m[{i,j}] = cur++;
        }
    }
    ghosts = cur-1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(grid[i][j]=='H')
                m[{i,j}] = cur++;
        }
    }
    human = cur-1-ghosts;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(grid[i][j]=='G'){
                FindDistance(i,j);
            }
        }
    }
    int lo=0,hi=630,res=-1,mid;

    while(lo<=hi){
        memset(flow,0,sizeof(flow));
        memset(cap,0,sizeof(cap));

        for(i=1;i<=ghosts;i++)///connect global source 0 with all ghosts
        {
            cap[0][i] = 1;
        }
        for(i=1+ghosts;i<cur;i++)/// connect global sink cur with all human
        {
            cap[i][cur] = 1;
        }

        mid = (lo+hi)/2;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(grid[i][j]!='G')
                    continue;
                for(int k=1;k<=n;k++)
                {
                    for(int l=1;l<=n;l++)
                    {
                        if(grid[k][l]=='H' && level[i][j][k][l]<=mid)/// if distance between a ghosts and human is less than mid, than connect two nodes
                        {
                            cap[m[{i,j}]][m[{k,l}]] = 1e9;
                        }
                    }
                }
            }
        }
        int curflow = MxFlowFuN(0,cur);
        if(curflow>=human){
            res = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    if(res==-1)
        printf("Case %d: Vuter Dol Kupokat\n",t);
    else
        printf("Case %d: %d\n",t,res*2+2);
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


#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1000];
int vis[1000],level[1005],parent[1005];
void BFS(int start)
{
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    memset(parent,-1,sizeof(parent));
    queue<int> q;
    q.push(start);
    vis[start]=1,level[start]=0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                level[v] = level[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
}
int main()
{
    int i,n,u,v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    BFS(1);
    cout<<level[7]<< ' '<<parent[7]<<endl;
}

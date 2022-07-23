#include<bits/stdc++.h>
using namespace std;

#define sz 1005

int n,m,vis[sz],curtime=1,compno=0,ans=1;
vector<int> graph[sz],revgraph[sz],dag[sz],component[sz];
stack<int> stk;
vector<pair<int,int>> edges;
set<int> node;
map<int,int> compress;


void Clean()
{
    ans=1;
    node.clear();
    compress.clear();
    edges.clear();
    while(!stk.empty())
        stk.pop();
    for(int i=0;i<sz;i++)
    {
        graph[i].clear();
        revgraph[i].clear();
        component[i].clear();
        dag[i].clear();
    }

}
void DFS1(int u)
{
    vis[u]=1;
    for(auto v: graph[u])
    {
        if(!vis[v]){
            DFS1(v);
        }
    }
    stk.push(u);
}

void DFS2(int u,int compno)
{
    vis[u]=compno;
    component[compno].push_back(u);
    for(auto v: revgraph[u])
    {
        if(!vis[v]){
            DFS2(v,compno);
        }
    }
}


void DFS(int u)
{
    vis[u]=1;
    if(dag[u].size()>1)
    {
        ans=0;
        return ;
    }
    for(auto v:dag[u])
    {
        if(!vis[v])
            DFS(v);
    }

}


void Solve(int t)
{
    int i, j, u, v, wish, x = 0;

    scanf("%d",&n);
    node.insert(0);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&wish);
        for(j=1;j<=wish;j++)
        {
            scanf("%d %d",&u,&v);
            edges.push_back({u,v});
            node.insert(u);
            node.insert(v);

        }
    }

    for(auto it:node)
    {
        compress[it] = ++x;
    }
    for(auto it:edges)
    {
        u = compress[it.first];
        v = compress[it.second];
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    ///SCC call
    memset(vis,0,sizeof(vis));
    for(i=1;i<=x;i++)
    {
        if(!vis[i])
            DFS1(i);
    }
    int compno=0;
    memset(vis,0,sizeof(vis));
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        if(!vis[top])
        {
            DFS2(top,++compno);
        }
    }
    ///make DAG to SCC
    for(u=1;u<=x;u++)
    {
        int nu=vis[u];
        for(auto v:graph[u])
        {
            int nv=vis[v];
            if(nu!=nv)
                dag[nu].push_back(nv);
        }
    }

    int source = vis[1];
    memset(vis,0,sizeof(vis));
    DFS(source);
    for(i=1;i<=compno;i++)
    {
        ans &= vis[i];
    }

    if(ans)
        printf("Case %d: YES\n",t);
    else
        printf("Case %d: NO\n",t);
    Clean();
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


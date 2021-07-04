#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 150005
vector<ll> graph[sz];
ll vis[sz],node,edge;

void DFS(int u)
{
    vis[u]  = 1;
    node++;
    for(auto v:graph[u])
    {
        edge++;
        if(!vis[v])
        {
            DFS(v);
        }
    }
}
int main()
{
    ll n,m,i,u,v,fg=1;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            node = 0,edge = 0;
            DFS(i);
            edge/=2;
            if((node*(node-1))/2 != edge)
                fg=0;
        }
    }
    if(fg)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

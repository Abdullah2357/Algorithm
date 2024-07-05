#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

ll n, m, low[sz], disc[sz], timer = 1;
vector<int> graph[sz];
vector<pair<int,int>> bridge;

void DFS(int u,int par)
{
    low[u] = timer;
    disc[u] = timer;
    timer++;
    for(auto v: graph[u])
    {
        if(v==par)
            continue;
        if(!disc[v])
        {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u])
            {
                bridge.push_back({u,v});
            }
        }
        else
        {
            low[u] = min(low[u], low[v]);
        }
    }
}

void Solve(int t)
{
    int i, u, v;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1,0);
    cout<<bridge.size()<<endl;
     for(i = 0;i<(int)bridge.size();i++)
     {
        cout<<bridge[i].first << ' '<<bridge[i].second<<endl;
     }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,T=1;
    // cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

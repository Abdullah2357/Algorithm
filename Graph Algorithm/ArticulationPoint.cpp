#include<bits/stdc++.h>
#define ll      long long
#define MOD     1000000007
#define sz      200005
using namespace std;

ll n, m, low[sz], disc[sz], timer = 1, AP[sz];
vector<int> graph[sz];


int DFS_AP(int u,int par)
{
    low[u] = timer;
    disc[u] = timer;
    timer++;
    int children = 0;
    for(auto v: graph[u])
    {
        if(v==par)
            continue;
        if(!disc[v])
        {
            children++;
            DFS_AP(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= disc[u])
            {
                AP[u] = 1;
            }
        }
        else
        {
            low[u] = min(low[u], low[v]);
        }
    }
    return children;
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
    for(i=1;i<=n;i++)
    {
        if(!disc[i])
            AP[i] = DFS_AP(i,0)>1;
    }
    for(i=1;i<=n;i++)
        if(AP[i])
            cout<<i<< ' ';

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

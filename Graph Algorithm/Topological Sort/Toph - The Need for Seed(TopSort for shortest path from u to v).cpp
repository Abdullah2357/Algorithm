#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 100005

ll n,diff[sz],m,l,indeg[sz],in[sz];

vector<ll>graph[sz],cost[sz];
ll dp[sz];

void TopBFS(int n,int s)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
        dp[i] = 1e18;
    }
    dp[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            dp[v] = min(dp[v],cost[u][i]+dp[u]);
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
}

void Clean(int n)
{
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        cost[i].clear();
        in[i] = 0;
    }
}

void Solve(int t)
{
    ll i, j, fg = 0, x, y, ans = 0;
    scanf("%lld %lld %lld",&n,&m,&l);
    Clean(n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&diff[i]);
    }
    for(i=1;i<=m;i++)
    {
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        if(diff[u]<diff[v])
            swap(u,v);
        graph[u].push_back(v);
        cost[u].push_back(w);
        in[v]++;
    }
    while(l--)
    {
        scanf("%lld %lld",&x,&y);
        for(i=0;i<n;i++)
        {
            indeg[i] = in[i];
        }
        TopBFS(n, x);
        if(dp[y]==1e18)
            dp[y] = -1;
        printf("%lld\n",dp[y]);
    }
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

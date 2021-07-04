#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005

ll n, a[sz], dist[sz], sum[sz], dp[sz], cursum, ans = 0;
vector<ll> graph[sz];

void DFS(int u,int par)
{
    sum[u] = a[u];
    for(auto v:graph[u])
    {
        if(v!=par)
        {
            dist[v] = dist[u]+1;
            DFS(v,u);
            sum[u] += sum[v];
        }
    }
}
ll FuN(int u,int par)
{
    for(auto v:graph[u])
    {
        if(v!=par)
        {
            dp[v] = dp[u] + sum[1] - 2*sum[v];
            FuN(v, u);
        }
    }
}
int main()
{
    ll u, v, i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dist[1] = 0;
    DFS(1,0);
    for(i=1;i<=n;i++)
    {
        ans+=a[i]*dist[i];
    }
    dp[1] = ans;
    FuN(1, 0);
    for(i=1;i<=n;i++)
    {
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}


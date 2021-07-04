#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;
vector<ll> graph[100005];

ll n,dp[100005][2],vis[100005];

ll FuN(ll u,ll par_colour)
{
    vis[u]=1;
    if(graph[u].size()==1 && vis[graph[u][0]]==1)
    {
        if(par_colour==0)
            return 2;
        else if(par_colour==1)
            return 1;
    }
    if(dp[u][par_colour]!=-1)
        return dp[u][par_colour];
    ll white=1,black=1;
    for(ll i=0;i<graph[u].size();i++)
    {
        ll v=graph[u][i];
        if(vis[v])
            continue;
        white *= FuN(v,0);
        if(par_colour==0)
            black *= FuN(v,1);
        white%=MOD;
        black%=MOD;
    }
    dp[u][0] = (white+black)%MOD;
    dp[u][1] = white;
    return dp[u][par_colour];
}
int main()
{
    cin>>n;
    ll u,v,i;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    ll ans = FuN(1,0);
    cout<<ans<<endl;
}



#include<bits/stdc++.h>
using namespace std;


vector<int> graph[100005];
int n,m,u,v,dp[100005];

int FuN(int u)
{
    if(graph[u].size()==0)
        return 0;
    if(dp[u]!=-1)
        return dp[u];
    int ret1=0,ret2=0;
    for(int i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        ret1 = 1+FuN(v);
        ret2 = max(ret1,ret2);
    }
    return dp[u] = ret2;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,FuN(i));
    }
    cout<<ans<<endl;
    return 0;
}



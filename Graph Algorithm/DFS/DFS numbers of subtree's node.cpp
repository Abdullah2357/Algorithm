#include<bits/stdc++.h>
using namespace std;

#define sz 100005
int vis[sz],cnt[sz];
vector<int>graph[sz];

void DFS(int u)
{
    vis[u] = 1;
    cnt[u] = 1;
    for(auto v : graph[u]){
        if(!vis[v]){
            DFS(v);
            cnt[u] += cnt[v];
        }
    }
}

int main()
{
    int i,j,k,n,u,v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    DFS(1);
    for(i=1;i<=n;i++)
    {
        cout<<"Cnt of "<<i<<" = "<< cnt[i]<<endl;
    }
    return 0;
}

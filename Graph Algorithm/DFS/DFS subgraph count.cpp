#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
int vis[1005],sub[1005];
void DFS(int u,int n)
{
    vis[u]=n;
    for(auto v: graph[u])
    {
        if(!vis[v])
            DFS(v,n);
    }
}
int main()
{
    int n,u,v,i,edg,tot=0;
    cin>>n>>edg;
    for(i=1;i<=edg;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            tot++,DFS(i,tot);
    }
    cout<<tot<< ' '<<vis[8]<<endl;
}

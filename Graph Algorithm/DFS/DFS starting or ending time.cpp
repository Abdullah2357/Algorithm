#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10005];
int vis[1005],start_time[1005],end_time[1005],st=1;
void DFS(int u)
{
    vis[u] = 1;
    start_time[u] = st++;
    for(auto v: graph[u])
    {
        if(!vis[v])
            DFS(v);
    }
    end_time[u] = st++;
}
int main()
{
    int n,i,u,v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1);
    for(i=1;i<=n;i++)
    {
        cout<<i<< ' '<<start_time[i]<< ' '<<end_time[i]<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10005];
vector<int> cost[10005];
int d[10005];

struct node{
    int u,cost;
    node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
    bool operator < (const node &p)const{
        return cost > p.cost;
    }
};

void dijkstra(int source,int n)
{
    priority_queue<node> pq;
    pq.push(node(source,0));
    d[source]=0;
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u=top.u;
        if(top.cost > d[u])
            continue;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(top.cost+cost[u][i] < d[v])
            {
                d[v]=top.cost+cost[u][i];
                pq.push(node(v,d[v]));
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<source<<"--> "<<i<<" = "<<d[i]<<endl;

}
int main()
{
    int n,m,i,u,v,w;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    for(i=1;i<=n;i++)
        d[i]=1e9;
    int source;
    cin>>source;
    dijkstra(source,n);

}

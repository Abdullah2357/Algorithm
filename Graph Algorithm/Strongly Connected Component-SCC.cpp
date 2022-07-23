#include<bits/stdc++.h>
using namespace std;

#define sz 100005

int n,m,vis[sz],start_time[sz],end_time[sz],curtime=1,compno=0;
vector<int> graph[sz],revgraph[sz];
stack<int> stk;
vector<int> component[sz];

void DFS(int u)
{
    vis[u]=1;
    start_time[u] = curtime++;
    for(auto v: graph[u])
    {
        if(!vis[v]){
            DFS(v);
        }
    }
    end_time[u] = curtime++;
    stk.push(u);
}
void DFS2(int u,int compno)
{
    vis[u]=1;
    component[compno].push_back(u);
    for(auto v: revgraph[u])
    {
        if(!vis[v]){
            DFS2(v,compno);
        }
    }
}



int main()
{
    int i,u,v;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++){
        if(!vis[i])
            DFS(i);
    }
    for(i=1;i<=n;i++)
        cout<<start_time[i]<< ' '<<end_time[i]<<endl;

    memset(vis,0,sizeof(vis));

    while(!stk.empty())
    {
        u = stk.top();
        stk.pop();
        if(!vis[u])
        {
            DFS2(u,++compno);
        }
    }
    for(i=1;i<=compno;i++)
    {
        for(auto it:component[i])
            cout<<it<< ' ';
        cout<<endl;
    }
}


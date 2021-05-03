#include<bits/stdc++.h>
using namespace std;

#define sz 100005

int indeg[sz];

vector<int> graph[sz];
vector<int> ans;

void TopBFS(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:graph[u])
        {
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
}
void Clean(int n)
{
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        indeg[i] = 0;
    }
}
int main()
{
    int u,v,i,n,m;
    cin>>n>>m;
    Clean(n);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    TopBFS(n);
    for(auto it:ans)
        cout<<it<<' ';
    cout<<endl;
}

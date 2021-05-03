#include<bits/stdc++.h>
using namespace std;

#define sz 100005

int indeg[sz];

vector<int> graph[sz];
vector<int> ans;

struct info
{
    int a;
    info(int _a)
    {
        a = _a;
    }
    bool operator < (const info&p) const
    {
        return a>p.a;
    }
};
void TopBFS(int n)
{
    priority_queue<info> pq;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            pq.push(info(i));
    }
    while(!pq.empty())
    {
        info u = pq.top();
        pq.pop();
        ans.push_back(u.a);
        for(auto v:graph[u.a])
        {
            indeg[v]--;
            if(indeg[v]==0)
                pq.push(info(v));
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
    if(ans.size()!=n){
        cout<<"Sandro fails.\n";
        return 0;
    }
    for(auto it:ans)
        cout<<it<<' ';
    cout<<endl;
    return 0;
}


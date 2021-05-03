#include<bits/stdc++.h>
using namespace std;

#define sz 10005

int indeg[sz],indeg2[sz],level[sz];

vector<int> graph[sz];
vector<pair<int,int>> ans;

void TopBFS(int n)
{
    queue<int> pq;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0){
            pq.push(i);
            ans.push_back(make_pair(1,i));
            level[i]=  1;
        }
    }
    while(!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        for(auto v:graph[u])
        {
            indeg[v]--;
            if(indeg[v]==0){
                pq.push((v));
                level[v] = level[u]+1;
                ans.push_back(make_pair(level[v],v));
            }
        }
    }
}
void Clean(int n)
{
    ans.clear();
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        indeg[i] = 0;
        indeg2[i] = 0;
    }
}
void Solve(int t)
{

    int u,v,i,n,m,Rank = 1;

    scanf("%d %d",&n,&m);
    Clean(n);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        graph[v].push_back(u);
        indeg[u]++;
    }
    TopBFS(n);
    printf("Scenario #%d:\n",t);
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

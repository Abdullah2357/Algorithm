#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz  100005

vector<ll> graph[2][sz];
const int MOD = 1e9+7,p = 31;
ll vis[2][sz],subtreesz[2][sz],hashvalue[2][sz];

void DFS(int u,int treeno,int level,ll power)
{
    vis[treeno][u] = 1;
    subtreesz[treeno][u] = 1;
    for(auto v: graph[treeno][u])
    {
        if(!vis[treeno][v])
        {
            DFS(v,treeno,level+1,(power*p)%MOD);
            hashvalue[treeno][u] = (hashvalue[treeno][u]+ hashvalue[treeno][v])%MOD;
            subtreesz[treeno][u] += subtreesz[treeno][v];
        }
    }
    hashvalue[treeno][u] = (hashvalue[treeno][u]+(subtreesz[treeno][u]*power)%MOD)%MOD;
}
int main()
{
    ll n1,n2,u,v,i;

    cin>>n1;
    for(i=1;i<n1;i++)
    {
        cin>>u>>v;
        graph[0][u].push_back(v);
        graph[0][v].push_back(u);
    }

    cin>>n2;
    for(i=1;i<n2;i++)
    {
        cin>>u>>v;
        graph[1][u].push_back(v);
        graph[1][v].push_back(u);
    }
    DFS(1, 0, 1, p);
    DFS(1, 1, 1, p);
    if(hashvalue[0][1]==hashvalue[1][1])
        cout<<"The Tree Is Identical.\n";
    else
        cout<<"The Tree Is NOT Identical.\n";
}

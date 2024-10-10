#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define Input               freopen("in.txt","r",stdin)
#define Output              freopen("out.txt","w",stdout)
#define MOD                 1000000007
#define sz                  400005
using namespace std;

ll n, m, h, a[sz], d[sz], d2[sz];
std::vector<ll> graph[sz], cost[sz];

struct node
{
    ll u, cost;
    node(ll _u, ll  _cost){
        u = _u;
        cost = _cost;
    }
    bool operator < (const node &p)const{
        return cost > p.cost;
    }
};


void dijkstra(int source)
{
    for(int i=1;i<=2*n;i++){
        d[i] = 1e18;
    }
    priority_queue<node> pq;
    pq.push(node(source,0));
    d[source] = 0;
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        ll u = top.u;
        if(top.cost > d[u])
            continue;
        for(int i = 0; i<graph[u].size(); i++){
            ll v  = graph[u][i];
            ll w = cost[u][i];
            if(top.cost+w < d[v]){
                d[v] = top.cost + w;
                pq.push(node(v, d[v]));
            }
        }
    }
}
void Solve(int t)
{
    ll i, j, ans = 1e18, fg = 0;
    cin>>n>>m>>h;
    for(i=1;i<=2*n;i++){
        graph[i].clear();
        cost[i].clear();
    }
    for(i = 1; i <= h; i++)
    {
        cin>>a[i];
        graph[a[i]].push_back(a[i]+n);
        graph[a[i]+n].push_back(a[i]);
        cost[a[i]].push_back(0);
        cost[a[i]+n].push_back(0);
    }

    for(i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

        graph[u+n].push_back(v+n);
        graph[v+n].push_back(u+n);
        cost[u+n].push_back(w/2);
        cost[v+n].push_back(w/2);
    }

    dijkstra(1);
    for(i=1;i<=n;i++){
        d2[i]= min(d[i], d[i+n]);
    }
    dijkstra(n);
    for(i=1;i<=n;i++){
        d[i]= min(d[i], d[i+n]);
    }
    for(i=1;i<=n;i++){
        ans = min(ans,  max(d[i], d2[i]));
    }
    if(ans==1e18)
        ans = -1;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}

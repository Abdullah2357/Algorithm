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
#define sz                  200005
using namespace std;

ll n, m, q[sz], res[sz];

int par[sz];
void MakeSet(int n)
{
    for(int i=1;i<=n;i++)
        par[i]=i;
}
int FindPar(int u)
{
    if(par[u]==u)
        return u;
    return par[u] = FindPar(par[u]);
}
void Union(int u, int v)
{
    int parU = FindPar(u);
    int parV = FindPar(v);
    if(parU != parV)
    {
        par[parV] = parU;
    }
}

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w){
        u = _u;
        v =_v;
        w = _w;
    }
    bool operator < (const edge &p)const{
        return w<p.w;
    }
};

void Solve(int t)
{
    ll i, j, ans = 0, fg = 0;
    cin>>n>>m;
    map<ll,ll> fre;
    for(i=1;i<=n;i++){
        fre[i] = 1;
    }

    MakeSet(n);
    vector<edge> Edge;
    for(i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        Edge.push_back(edge(u, v, w));
    }
    sort(Edge.begin(), Edge.end());
    vector<pair<int,int>> query;
    for(i=1;i<=m;i++){
        cin>>q[i];
        query.push_back({q[i], i});
    }
    sort(all(query));
    j = 0;
    for(i=0;i<m;i++){
        while(j<n-1 && Edge[j].w <= query[i].F){
            int p1 = FindPar(Edge[j].u);
            int p2 = FindPar(Edge[j].v);
            if(p1 != p2){
                ans -= (fre[p1]*(fre[p1]-1))/2;
                ans -= (fre[p2]*(fre[p2]-1))/2;
                fre[p1] += fre[p2];
                fre[p2] = 0;
                ans += (fre[p1]*(fre[p1]-1))/2;
                Union(p1, p2);
            }
            j++;
        }
        res[query[i].S] = ans;
    }
    for(i=1;i<=m;i++)
        cout<<res[i]<< ' ';
    cout<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    // cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005
const ll MOD = 1e9;
ll par[sz],used[sz],subGraphSZ[sz];
struct info{
    ll u,v,w;
    info(ll _u,ll _v,ll _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const info&p) const{
        return w<p.w;
    }
};
vector<info> edge;

ll FindPar(ll u)
{
    if(par[u]==u)
        return u;
    return par[u] = FindPar(par[u]);
}

void Union(ll u,ll v)
{
    ll parU = FindPar(u);
    ll parV = FindPar(v);
    subGraphSZ[parU] = (subGraphSZ[parU] +subGraphSZ[parV]);
    used[parU] = (used[parU]+ used[parV]);
    used[parV] = 0;
    par[parV] = parU;
}
ll MST(ll n)
{
    sort(edge.rbegin(),edge.rend());
    ll i, cnt = 0, s = 0,ans=0;
    for(i=1;i<=n;i++){
        par[i] = i,used[i]=0,subGraphSZ[i]=1;
    }
    for(i=0;i<edge.size();i++)
    {
        ll parU = FindPar(edge[i].u);
        ll parV = FindPar(edge[i].v);
        if(parU!=parV)
        {
            Union(edge[i].u,edge[i].v);
            ll x = (subGraphSZ[parU]*(subGraphSZ[parU]-1))/2;
            ans += ((x-used[parU]))*s;
            ans%=MOD;
            //cout<<ans<<endl;
            used[parU] = x;
            s += edge[i].w;
            s%=MOD;
        }
        else
            s = (s+ edge[i].w)%MOD;
    }
    return ans;
}
int main()
{
    ll n,m,i,j,u,v,w,ans=0,tot_cost=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        tot_cost+=w;
        tot_cost%=MOD;
        if(u>v)
            swap(u,v);
        edge.push_back(info(u,v,w));
    }
    ans = MST(n);
    ll x=0;
    for(i=1;i<=n;i++)
    {
        x+=used[i];
        x%=MOD;
    }
    //cout<<x<<endl;
    ans = (x*tot_cost) - ans;
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}

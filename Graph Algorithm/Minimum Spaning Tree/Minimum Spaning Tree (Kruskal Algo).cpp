#include<bits/stdc++.h>
using namespace std;

#define sz 100005
int par[sz];
struct info{
    int u,v,w;
    info(int _u,int _v,int _w)
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

int FindPar(int u)
{
    if(par[u]==u)
        return u;
    return par[u] = FindPar(par[u]);
}
int MST(int n)
{
    sort(edge.begin(),edge.end());
    int i, cnt = 0, s = 0;
    for(i=1;i<=n;i++)
        par[i] = i;
    for(i=0;i<edge.size();i++)
    {
        int parU = FindPar(edge[i].u);
        int parV = FindPar(edge[i].v);
        if(parU!=parV)
        {
            par[parU] = parV;
            cnt++;
            s += edge[i].w;
            if(cnt==n-1)
                break;
        }
    }
    return s;
}
int main()
{
    int n,m,i,u,v,w;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        edge.push_back(info(u,v,w));
    }
    cout<<MST(n)<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define sz 10005
int par[sz],Airport;
struct info{
    int u,v,w,is_Airport;
    info(int _u,int _v,int _w,int _is_Airport)
    {
        u = _u;
        v = _v;
        w = _w;
        is_Airport = _is_Airport;
    }
    bool operator < (const info&p) const{
        if(w==p.w)
            return is_Airport > p.is_Airport;
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
    int i;
    int s = 0;
    for(i=0;i<=n;i++)
        par[i] = i;
    for(i=0;i<edge.size();i++)
    {
        int parU = FindPar(edge[i].u);
        int parV = FindPar(edge[i].v);
        if(parU!=parV)
        {
            par[parU] = parV;
            s += edge[i].w;
            if(edge[i].u==0)
                Airport++;
        }
    }
    return s;
}

void Solve(int t)
{
    int n,m,i,u,v,w,A;
    Airport = 0;
    scanf("%d %d %d",&n,&m,&A);
    edge.clear();
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        edge.push_back(info(u,v,w,0));
    }
    for(i=1;i<=n;i++)
    {
        edge.push_back(info(0,i,A,1));
    }
    sort(edge.begin(),edge.end());
    int Cost = MST(n);
    printf("Case %d: %d %d\n",t,Cost,Airport);
}
int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define sz 205
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
    int s=0,cnt=0,i;
    for(i=1;i<=n;i++)
        par[i]=i;
    sort(edge.begin(),edge.end());
    for(i=0;i<edge.size();i++)
    {
        int parU = FindPar(edge[i].u);
        int parV = FindPar(edge[i].v);
        if(parU!=parV)
        {
            par[parU] = parV;
            s+=edge[i].w;
            cnt++;
        }
        else
        {
            edge.erase(edge.begin()+i);
            i--;
        }
    }
    if(cnt==n-1)
        return s;
    return -1;
}
void Solve(int t)
{
    int n, m, i, u, v, w, weeks;
    scanf("%d %d", &n, &weeks);
    edge.clear();
    printf("Case %d:\n", t);
    for(i=1; i <= weeks; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        edge.push_back(info(u, v, w));
        int ans = MST(n);
        printf("%d\n", ans);
    }
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

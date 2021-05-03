#include<bits/stdc++.h>
using namespace std;

#define sz 55
int par[sz],a[sz][sz];
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
    if(cnt<n-1)
        return -1;
    return s;
}
void Solve(int t)
{
    int n,m,i,j,u,v,w,total = 0;
    scanf("%d",&n);
    edge.clear();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            total += a[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i][j]>0 && a[j][i]>0)
            {
                edge.push_back(info(i,j,min(a[i][j],a[j][i])));
            }
            else if(a[i][j]>0)
                edge.push_back(info(i,j,a[i][j]));
        }
    }
    sort(edge.begin(),edge.end());
    int Used = MST(n);
    if(Used==-1)
        printf("Case %d: -1\n",t);
    else
        printf("Case %d: %d\n",t,total-Used);
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


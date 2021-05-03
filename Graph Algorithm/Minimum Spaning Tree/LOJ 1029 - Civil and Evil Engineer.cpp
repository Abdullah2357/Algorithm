#include<bits/stdc++.h>
using namespace std;

#define sz 105
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
    int i, cnt = 0, s = 0;
    for(i=0;i<=n;i++)
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
            if(cnt==n)
                break;
        }
    }
    return s;
}
void Solve(int t)
{
    int n,m,i,u,v,w;
    scanf("%d",&n);
    edge.clear();
    while(1)
    {
        scanf("%d %d %d",&u,&v,&w);
        if(u==0 && v==0 && w==0)
            break;
        edge.push_back(info(u,v,w));
    }
    sort(edge.begin(),edge.end());
    int Best = MST(n);
    reverse(edge.begin(),edge.end());
    int Worst = MST(n);
    if((Best+Worst)%2==0)
        printf("Case %d: %d\n",t,(Best+Worst)/2);
    else
        printf("Case %d: %d/2\n",t,Best+Worst);
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

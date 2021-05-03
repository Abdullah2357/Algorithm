
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
    int n,m,i,u,v,w,cityNo=1;
    scanf("%d",&n);
    edge.clear();
    string city1,city2;
    map<string,int> fre;
    for(i=1;i<=n;i++)
    {
        cin>>city1>>city2;
        //scanf("%s %s %d",city1,city2,&w);
        scanf("%d",&w);
        if(fre[city1]==0)
            fre[city1]=cityNo++;
        if(fre[city2]==0)
            fre[city2]=cityNo++;
        edge.push_back(info(fre[city1],fre[city2],w));
    }
    sort(edge.begin(),edge.end());
    int ans = MST(cityNo-1);
    if(ans==-1)
        printf("Case %d: Impossible\n",t);
    else
        printf("Case %d: %d\n",t,ans);
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

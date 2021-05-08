#include<bits/stdc++.h>
using namespace std;

#define sz 100005

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
orderset<pair<int,int>> st[sz];

int par[sz];
void MakeSet(int n)
{
    for(int i=1;i<=n;i++){
        par[i]=i;
        st[i].clear();
    }
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
    par[parV] = parU;
}
void AddTwoSubGraph(int u,int v)
{
    int parU = FindPar(u);
    int parV = FindPar(v);
    if(parU==parV)
        return ;
    if(st[parV].size()<=st[parU].size())
    {
        for(auto it:st[parV])
        {
            st[parU].insert(it);
        }
        st[parV].clear();
        Union(u, v);
    }
    else
    {
        for(auto it:st[parU])
        {
            st[parV].insert(it);
        }
        st[parU].clear();
        Union(v,u);
    }
}
int main()
{
    int n, q, i, u, v,t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&q);
        MakeSet(n);
        printf("Case %d:\n",t);
        int cnt=0;
        while(q--)
        {
            int id,u,v,x,time,l,r;
            scanf("%d",&id);
            if(id==0)
            {
                scanf("%d %d",&u,&v);
                AddTwoSubGraph(u,v);
            }
            else if(id==1)
            {
                scanf("%d %d",&u,&time);
                st[FindPar(u)].insert(make_pair(time,cnt++));
            }
            else
            {
                scanf("%d %d %d",&u,&l,&r);
                int parU = FindPar(u);
                int lb = st[parU].order_of_key(make_pair(l,0));
                int ub = st[parU].order_of_key(make_pair(r+1,0));
                printf("%d\n",ub-lb);
            }
        }
    }
    return 0;
}


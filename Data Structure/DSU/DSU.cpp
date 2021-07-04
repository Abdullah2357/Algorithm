#include<bits/stdc++.h>
using namespace std;

#define sz 100005

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
        par[parU] = parV;
    }
}
int main()
{
    int n, m, i, u, v;
    cin>>n>>m;
    MakeSet(n);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        Union(u, v);
    }
    for(i=1;i<=n;i++)
        cout<<FindPar(i)<< ' ';
    cout<<endl;
}

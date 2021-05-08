#include<bits/stdc++.h>
using namespace std;

#define sz 20005

int par[sz], subGraphSZ[sz],ans;
vector<pair<int,int>> edge;

void MakeSet(int n)
{
    for(int i=1;i<=n;i++){
        par[i]=i;
        subGraphSZ[i]=1;
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
    ans -= subGraphSZ[parU]*subGraphSZ[parV];
    subGraphSZ[parU] += subGraphSZ[parV];
    par[parV] = parU;
}

void Solve(int t)
{
    int n,i,x,a,b,q;
    cin>>n;
    MakeSet(n);
    map<int,int> mark;
    edge.clear();
    edge.push_back(make_pair(0,0));
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        edge.push_back(make_pair(a,b));
    }
    cin>>q;
    vector<int> v;
    while(q--)
    {
        char id;
        cin>>id;
        if(id=='R')
        {
            cin>>x;
            v.push_back(x);
            mark[x]=1;
        }
        else
        {
            v.push_back(0);
        }
    }
    ans = (n*(n-1))/2;
    for(i=1;i<n;i++)
    {
        if(!mark[i])
            Union(edge[i].first,edge[i].second);
    }
    vector<int> res;
    for(i=v.size()-1;i>=0;i--)
    {
        if(v[i]==0)
        {
            res.push_back(ans);
        }
        else
        {
            Union(edge[v[i]].first,edge[v[i]].second);
        }
    }
    reverse(res.begin(),res.end());
    for(auto it:res)
        cout<<it<<endl;
    //cout<<endl;
}
int main()
{
    int t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

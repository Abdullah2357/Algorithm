#include<bits/stdc++.h>
using namespace std;

#define sz 1005

int par[sz],a[sz],b[sz];
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
void Solve(int t)
{
    int n, m, i, u, v;
    cin>>n;
    MakeSet(n);
    vector<pair<int,int> > vec;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        if(FindPar(u)!=FindPar(v))
        {
            Union(u, v);
        }
        else
        {
            vec.push_back(make_pair(u,v));
        }
    }
    set<int> s;
    for(i=1;i<=n;i++)
    {
        s.insert(FindPar(i));
    }
    cout<<vec.size()<<endl;
    while(s.size()>1 && !vec.empty())
    {
        cout<<vec.back().first<< ' '<<vec.back().second<< ' '<<*s.begin()<< ' ';
        vec.pop_back();
        s.erase(s.begin());
        cout<<*s.begin()<<endl;
     //   cout<<"...................\n";
    }
    return ;

}
int main()
{
    int t,T=1;
    //cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

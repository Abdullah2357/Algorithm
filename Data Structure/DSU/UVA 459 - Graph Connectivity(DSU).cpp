#include<bits/stdc++.h>
using namespace std;

#define sz 100005

int par[30];
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
void Solve(int t,int T)
{
    int n, m, i, u, v;
    char ch;
    cin>>ch;
    getchar();
    n = ch-'A'+1;
    MakeSet(n);
    string s;
    while(getline(cin,s) && s!="")
    {
        Union((int)s[0]-'A'+1, (int)s[1]-'A'+1);
    }
    set<int> st;
    for(i=1;i<=n;i++)
        st.insert(FindPar(i));
    cout<<st.size()<<endl;
    if(t!=T)
        cout<<endl;

}
int main()
{
    int T,t;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        Solve(t,T);
    }
    return 0;
}

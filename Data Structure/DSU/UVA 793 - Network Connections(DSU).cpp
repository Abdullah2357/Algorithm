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
    int n, m, i, u, v,successful=0,unsuccessful=0;
    scanf("\n%d\n",&n);
    MakeSet(n);
    char s[100];
    char c;
    while(fgets(s,sizeof(s),stdin))
    {
        if(s[0]=='\n')
            break;
        sscanf(s,"%c %d %d",&c,&u,&v);
        if(c=='c')
        {
            Union(u, v);
        }
        else
        {
            if(FindPar(u)==FindPar(v))
                successful++;
            else
                unsuccessful++;
        }
    }
    if(t!=1)
        cout<<endl;
    printf("%d,%d\n",successful,unsuccessful);

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

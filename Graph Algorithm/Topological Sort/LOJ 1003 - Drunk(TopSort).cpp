#include<bits/stdc++.h>
using namespace std;

#define sz 10005

int indeg[sz];

vector<int> graph[sz];
vector<int> ans;

struct info
{
    int a;
    info(int _a)
    {
        a = _a;
    }
    bool operator < (const info&p) const
    {
        return a>p.a;
    }
};

void TopBFS(int n)
{
    priority_queue<info> pq;

    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            pq.push(info(i));
    }

    while(!pq.empty())
    {
        info u = pq.top();
        pq.pop();
        ans.push_back(u.a);
        for(auto v:graph[u.a])
        {
            indeg[v]--;
            if(indeg[v]==0)
                pq.push(info(v));
        }
    }

}
void Clean(int n)
{
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        indeg[i] = 0;
    }
}
void Solve(int t)
{
    Clean(sz-2);

    int u,v,i,n,m;
    string s,s2;
    int serialno=1;
    map<string,int> serial;

    scanf("%d",&m);

    for(i=1;i<=m;i++)
    {
        cin>>s>>s2;
        if(serial[s]==0)
            serial[s] = serialno++;
        if(serial[s2]==0)
            serial[s2] = serialno++;
        graph[serial[s]].push_back(serial[s2]);
        indeg[serial[s2]]++;
    }

    n = serialno-1;
    TopBFS(n);

    if(ans.size()==n)
        printf("Case %d: Yes\n",t);
    else
        printf("Case %d: No\n",t);
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

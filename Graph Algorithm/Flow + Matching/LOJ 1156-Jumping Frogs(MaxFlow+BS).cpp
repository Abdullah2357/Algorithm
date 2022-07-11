#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 205

bool vis[sz];
int n, d, cap[sz][sz], flow[sz][sz], par[sz],m;

map<int,int> nodeno;
vector<int> big,small;

bool BFS(int source, int destination)
{
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    par[source] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0;v<=destination;v++)
        {
            if(!vis[v] && (cap[u][v]-flow[u][v])>0)
            {
                q.push(v);
                par[v] = u;
                vis[v] = 1;
            }
        }
    }
    return vis[destination];
}

int MxFlowFuN(int source,int destination)
{
    int u, v, MxFlow = 0;
    while(BFS(source,destination))
    {
        int mnpathflow = 1e6;
        for(v = destination; v != source; v = par[v])
        {
            u = par[v];
            mnpathflow = min(mnpathflow, cap[u][v]-flow[u][v]);
        }
        for(v = destination; v != source; v = par[v])
        {
            u = par[v];
            flow[u][v] += mnpathflow;
            flow[v][u] -= mnpathflow;
        }
        MxFlow += mnpathflow;
    }
    return MxFlow;
}

bool possible(int value)
{
    memset(flow,0,sizeof(flow));
    memset(cap,0,sizeof(cap));

    if(value==d)
        cap[0][2*n+1]=1e6;
    int i,j;
    for(i=0;i<big.size();i++)
    {
        int u = nodeno[big[i]];
        cap[u][u+n] = 1e6;/// node split
        if(big[i]<=value)
            cap[0][u] = 1e6;
        if(d-big[i]<=value)
            cap[u+n][2*n+1] = 1e6;
        for(j=i+1;j<big.size();j++)
        {
            int v = nodeno[big[j]];
            if(abs(big[i]-big[j])<=value)
            {
                cap[u+n][v] = 1e6;
                cap[v+n][u] = 1e6;
            }
        }
        for(j=0;j<small.size();j++)
        {
            int v=  nodeno[small[j]];
            if(abs(big[i]-small[j])<=value)
            {
                cap[u+n][v] = 1e6;
                cap[v+n][u] = 1e6;
            }
        }
    }
    for(i=0;i<small.size();i++)
    {
        int u = nodeno[small[i]];
        cap[u][u+n] = 1;/// node split
        if(small[i]<=value)
            cap[0][u] = 1e6;
        if(d-small[i]<=value)
            cap[u+n][2*n+1] = 1e6;
        for(j=i+1;j<small.size();j++)
        {
            int v = nodeno[small[j]];
            if(abs(small[i]-small[j])<=value)
            {
                cap[u+n][v] = 1e6;
                cap[v+n][u] = 1e6;
            }
        }
    }


    int res = MxFlowFuN(0,2*n+1);
    return (res>1);

}
void Solve(int t)
{
    int i, j;
    nodeno.clear();
    big.clear();
    small.clear();



    scanf("%d %d",&n,&d);
    for(i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        m =0;
        for(j=2;j<s.size();j++)
        {
            m*=10;
            m +=(s[j]-'0');

        }
        if(s[0]=='B')
            big.push_back(m);
        else
            small.push_back(m);
        nodeno[m] = i;
    }


    int lo=0,hi=d,mid,res=d;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        if(possible(mid))
        {
            res = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    printf("Case %d: %d\n",t,res);
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

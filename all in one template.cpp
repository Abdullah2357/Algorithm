#include<bits/stdc++.h>
#define ll              long long
#define Input           freopen("input.txt","r",stdin)
#define Output          freopen("output.txt","w",stdout)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)         (a)*(b)/gcd(a,b)
#define PI              2*acos(0.0)
#define MOD             1000000007

using namespace std;

/** Sieve, PrimeFactorize, BigMOD **/
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};

/// Merge Sort Tree by orderset
orderset<pair<int,int>> s[400005];
map<int,int> m;

void Union(int node,int lft,int rgt)
{
    for(auto it:s[lft])
    {
        s[node].insert(it);
    }
    for(auto it:s[rgt])
    {
        s[node].insert(it);
    }
}
void Init(int node,int b,int e)
{
    if(b==e)
    {
        s[node].insert(make_pair(a[b],m[a[b]]++));
        return ;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    Union(node,lft,rgt);
//    merge(s[lft].begin(),s[lft].end(),s[rgt].begin(),s[rgt].end(),back_inserter(s[node]));
}

int Query(int node, int b, int e, int i,int j,int v)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        int l = s[node].order_of_key({v+1,0});
        return l;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    int p1 = Query(lft, b, mid, i, j, v);
    int p2 = Query(rgt, mid+1, e, i, j, v);

    return p1+p2;
}

///Segment Tree range update standard
int n,a[sz];

struct info{
    ll sum, prop;
}tree[sz*3];

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum = a[b];
        return ;
    }
    int lft = node<<1;
    int rgt = (node<<1)+1;
    int mid = (b+e)>>1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node].sum = tree[lft].sum +tree[rgt].sum;
}

void push_down(int node,int b,int e)
{
    tree[node].sum = tree[node].sum + tree[node].prop*(e-b+1);
    if(b!=e)
    {
        tree[node<<1].prop += tree[node].prop;
        tree[(node<<1)+1].prop += tree[node].prop;
    }
        tree[node].prop = 0;
}

ll Query(int node,int b,int e,int i,int j)
{
    if(tree[node].prop != 0)
        push_down(node, b, e);
    if(i>e || j<b)
        return 0;


    if(b>=i && e<=j)
        return tree[node].sum;

    int mid = (b+e)>>1;
    ll sum1 = Query(node<<1,b,mid,i,j);
    ll sum2 = Query((node<<1)+1,mid+1,e,i,j);

    return sum1+sum2;
}

void Update(int node,int b,int e,int i,int j,int x)
{
    if(tree[node].prop != 0){
        push_down(node, b, e);
    }
    if(i>e || j< b)
        return ;


    if(b>=i && e<=j)
    {
        tree[node].sum += x*(e-b+1);
        if(b!= e)
        {
            tree[node<<1].prop += x;
            tree[(node<<1)+1].prop += x;
        }
        return;
    }

    int mid = (b+e)>>1;

    Update(node<<1,b,mid,i,j,x);
    Update((node<<1)+1,mid+1,e,i,j,x);

    tree[node].sum = tree[node<<1].sum + tree[(node<<1)+1].sum;
}

/// mo's algo

int k,a[sz],ans[sz],sum=0;

struct Query{
    int index, l, r;
    bool operator < (const Query &other)const{
        int Block_own = l/k;
        int Block_other = other.l/k;
        if(Block_other == Block_own)
            return r < other.r;
        return Block_own < Block_other;
    }
}query[sz];

void Add(int i)
{
    sum += a[i];
}
void Remove(int i)
{
    sum -= a[i];
}

int main()
{
    int n, i, l = 0, r = -1, q;
    cin>>n;
    k = sqrt(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>query[i].l>>query[i].r;
        query[i].index = i;
    }
    sort(query,query+q);
    for(i=0;i<q;i++)
    {
        while(r < query[i].r) Add(++r);
        while(l < query[i].l) Remove(l++);
        while(r > query[i].r) Remove(r--);
        while(l > query[i].l) Add(--l);
        ans[query[i].index] = sum;
    }
    for(i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
/// DSU

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
/// Digit DP

ll FuN(int isStart,int isSmall, int pos, int num)
{
    if(pos==n)
    {
        if(num%d==0 && !isStart)
            return 1;
        return 0;
    }
    if(dp[isStart][isSmall][pos][num] != -1)
        return dp[isStart][isSmall][pos][num];
    ll ret = 0,canbeput = s[pos]-'0';
    if(isSmall)
        canbeput = 9;
    if(isStart)
    {
        ret += FuN(1,1,pos+1,num);
        ret %= MOD;
        for(int i=1;i<=canbeput;i++)
        {
            ret += FuN(0,isSmall|(i<(s[pos]-'0')), pos+1,(num+i)%d);
            ret %= MOD;
        }
    }
    else
    {
        for(int i=0;i<=canbeput;i++)
        {
            ret += FuN(0,isSmall|(i<(s[pos]-'0')), pos+1,(num+i)%d);
            ret %= MOD;
        }
    }
    return dp[isStart][isSmall][pos][num] = ret;
}
/// dijstra

vector<int> graph[10005];
vector<int> cost[10005];
int d[10005];

struct node{
    int u,cost;
    node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
    bool operator < (const node &p)const{
        return cost > p.cost;
    }
};

void dijkstra(int source,int n)
{
    priority_queue<node> pq;
    pq.push(node(source,0));
    d[source]=0;
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u=top.u;
        if(top.cost > d[u])
            continue;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(top.cost+cost[u][i] < d[v])
            {
                d[v]=top.cost+cost[u][i];
                pq.push(node(v,d[v]));
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<source<<"--> "<<i<<" = "<<d[i]<<endl;

}
int main()
{
    int n,m,i,u,v,w;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    for(i=1;i<=n;i++)
        d[i]=1e9;
    int source;
    cin>>source;
    dijkstra(source,n);

}
///Minimum Spaning Tree/


#define sz 100005
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
    sort(edge.begin(),edge.end());
    int i, cnt = 0, s = 0;
    for(i=1;i<=n;i++)
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
    return s;
}
///topsort


int indeg[sz];

vector<int> graph[sz];
vector<int> ans;

void TopBFS(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:graph[u])
        {
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
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
int main()
{
    int u,v,i,n,m;
    cin>>n>>m;
    Clean(n);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    TopBFS(n);
    for(auto it:ans)
        cout<<it<<' ';
    cout<<endl;

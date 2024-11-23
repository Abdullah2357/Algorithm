#include<bits/stdc++.h>
#define ll                  long long
#define endl                '\n'
#define F                   first
#define S                   second
#define all(a)              (a.begin()),(a.end())
#define UNIQUE(X)           (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)      (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define ms(a,b)             memset(a, b, sizeof(a))
#define Input               freopen("in.txt","r",stdin)
#define Output              freopen("out.txt","w",stdout)
#define MOD                 1000000007
#define sz                  200005
using namespace std;

ll n, a[sz], h[sz], dp[sz], tree[3*sz];

void Build(int node, int b, int e)
{
    if(b==e){
        tree[node] = 0;
        return ;
    }
    int lft = 2*node;
    int rgt = 2*node + 1;
    int mid = (b+e)/2;

    Build(lft, b, mid);
    Build(rgt, mid+1, e);

    tree[node] = max(tree[lft], tree[rgt]);
}

ll Query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j){
        return tree[node];
    }

    int lft = 2*node;
    int rgt = 2*node + 1;
    int mid = (b+e)/2;

    ll q1 = Query(lft, b, mid, i, j);
    ll q2 = Query(rgt, mid+1, e, i, j);
    return max(q1, q2);
}

void Update(int node, int b, int e, int i, ll value)
{
    if(i>e || i<b)
        return ;
    if(b>=i && e<=i){
        tree[node] = value;
        return ;
    }

    int lft = 2*node;
    int rgt = 2*node + 1;
    int mid = (b+e)/2;

    Update(lft, b, mid, i, value);
    Update(rgt, mid+1, e, i, value);

    tree[node] = max(tree[lft], tree[rgt]);
}

void Solve(int t)
{
    ll i, j, ans = 0, fg = 0, LIS = 0;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>h[i];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
    }

    Build(1, 1, n);

    for(i=1;i<=n;i++){
        ll cur = a[i] + Query(1, 1, n, 1, h[i]-1);
        ans = max(ans, cur);
        Update(1, 1, n, h[i], cur);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    // cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}

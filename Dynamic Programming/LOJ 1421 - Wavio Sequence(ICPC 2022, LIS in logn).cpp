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
#define sz                  100005
using namespace std;

ll n, a[sz], d[sz], d2[sz], t[sz], tree[3*sz];

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

int Query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j){
        return tree[node];
    }

    int lft = 2*node;
    int rgt = 2*node + 1;
    int mid = (b+e)/2;

    int q1 = Query(lft, b, mid, i, j);
    int q2 = Query(rgt, mid+1, e, i, j);
    return max(q1, q2);
}

void Update(int node, int b, int e, int i, int value)
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
    ll i, j, ans = 0, fg = 0, cnt = 1;
    cin>>n;
    std::vector<pair<int,int>> v;
    for(i = 1; i <= n; i++)
    {
        cin>>a[i];
        v.push_back({a[i], i});
    }
    sort(all(v));
    map<int, int> m;
    for(i=0;i<n;i++){
        if(m[v[i].F]==0)
            m[v[i].F] = cnt++;
        a[v[i].S] = m[v[i].F];
    }

    Build(1, 1, n);
    for(i=1;i<=n;i++){
        d[i] = Query(1, 1, n, 1, a[i]-1)+1;
        Update(1, 1, n, a[i], d[i]);
    }
    reverse(a+1, a+n+1);
    Build(1, 1, n);
    for(i=1;i<=n;i++){
        d2[i] = Query(1, 1, n, 1, a[i]-1)+1;
        Update(1, 1, n, a[i], d2[i]);
    }
    reverse(d2+1, d2+n+1);

    for(i=1;i<=n;i++){
        ans = max(ans, 2*(min(d[i], d2[i])) - 1);
    }

    cout<<"Case "<<t<<": "<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    cin>>T;
    for(t = 1; t <= T; t++)
        Solve(t);
    return 0;
}

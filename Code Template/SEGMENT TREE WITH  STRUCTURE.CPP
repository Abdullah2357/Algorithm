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

struct item {
    long long sum;
};

/**
 * We have to modify item, NEUTRAL_VALUE, single() according to problem
 * We may also need to change set(), Query(), Build()
 **/
struct segtree
{
    int size;
    vector<item> values;

    item NEUTRAL_VALUE = {0};

    item single(int v) {
        return {v};
    }
    item merge(item a, item b) {
        return {a.sum + b.sum};
    }

    void Init(int n) {
        size = 1;
        while (size < n) size *= 2;
        values.resize(2 * size);
    }

    void Build(vector<int> &a, int node, int b, int e) {
        if (b == e) {
            if (b < (int)a.size())
                values[node] = single(a[b]);
            return ;
        }
        int mid = (b + e) / 2;
        Build(a, node * 2 + 1, b, mid);
        Build(a, node * 2 + 2, mid + 1, e);
        values[node] = merge(values[2 * node + 1], values[2 * node + 2]);
    }

    void Build(vector<int> &a) {
        Build(a, 0, 0, size - 1);
    }

    void set(int i, int v, int node, int b, int e) {
        if (b == e) {
            values[node] = single(v);
            return ;
        }
        int mid = (b + e) / 2;
        if (i <= mid)
            set(i, v, 2 * node + 1, b, mid);
        else
            set(i, v, 2 * node + 2, mid + 1, e);
        values[node] = merge(values[2 * node + 1], values[2 * node + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size - 1);
    }

    item Query(int node, int b, int e, int l, int r) {
        if (b > r || e < l)  return NEUTRAL_VALUE;
        if (b >= l && e <= r) return values[node];
        int mid = (b + e) / 2;
        item s1 = Query(2 * node + 1, b, mid, l, r);
        item s2 = Query(2 * node + 2, mid + 1, e, l, r);
        return merge(s1, s2);
    }

    item Query(int l, int r) {
        return Query(0, 0, size - 1, l, r);
    }
};

void Solve(int t)
{
    ll n , m, i, v, ans = 0, fg = 0;
    cin >> n >> m;

    segtree st;
    st.Init(n);
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    st.Build(a);
    while (m--) {
        int operation;
        cin >> operation;
        if (operation == 1) {
            cin >> i >> v;
            st.set(i, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            item res = st.Query(l, r - 1);
            cout << res.sum << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    // cin >> T;
    for (t = 1; t <= T; t++)
        Solve(t);
    return 0;
}

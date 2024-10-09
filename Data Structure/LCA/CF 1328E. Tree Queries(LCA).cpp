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

int n, m, parent[20][sz], level[sz], a[sz];
std::vector<int> graph[sz];


void DFS(int u, int par)
{
    parent[0][u] = par;
    for(int i = 1; i<= 18; i++){
        parent[i][u] = parent[i-1][parent[i-1][u]];
    }
    for(auto v:graph[u])
    {
        if(v != par){
            level[v] = level[u] + 1;
            DFS(v, u);
        }
    }
}
int find_LCA(int x, int y)
{
    if(level[x] < level[y])
        swap(x, y);
    for(int i = 18; i >= 0; i--){
        if(level[parent[i][x]] < level[y])
            continue;
        x = parent[i][x];
    }

    if(x == y)
        return x;

    for(int i = 18;i >= 0; i--){
        if(parent[i][x] != parent[i][y])
        {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    return parent[0][x];
}


void Solve(int t)
{
    int i, j, ans = 0, fg = 0;
    cin>>n>>m;
    for(i = 1; i < n; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1, 1);
    while(m--){
        int k, mx = -1, mxlevel_node = 0;
        cin>>k;
        for(i=1;i<=k;i++){
            cin>>a[i];
            if(level[a[i]]>mx){ /// find the mx depth node which will be u
                mx = level[a[i]];
                mxlevel_node = a[i];
            }
        }

        fg = 1;
        for(i=1;i<=k;i++){
            // check if the nodes in the path or its parent in the path
            if(find_LCA(a[i], mxlevel_node) != a[i] && find_LCA(parent[0][a[i]], mxlevel_node)!=parent[0][a[i]]){
                fg = 0;
                break;
            }

        }
        cout<<(fg ? "YES\n":"NO\n");

    }
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

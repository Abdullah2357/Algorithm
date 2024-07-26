/*
find_LCA returns LCA of x,y
parent[i][x] means 2^i th parent of x
*/
#include<bits/stdc++.h>
#define sz 100005
using namespace std;

int parent[18][sz], level[sz], a[sz], b[sz], sum[sz], u[sz], v[sz];
std::vector<int> graph[sz];

void DFS(int u, int par)
{
    parent[0][u] = par;
    for(int i = 1; i<= 17; i++){
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
    for(int i = 17; i >= 0; i--){
        if(level[parent[i][x]] < level[y])
            continue;
        x = parent[i][x];
    }

    if(x == y)
        return x;

    for(int i = 17;i >= 0; i--){
        if(parent[i][x] != parent[i][y])
        {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    return parent[0][x];
}
map<pair<int,int>, int> m;

void DFS2(int u, int par)
{
    for(auto v: graph[u])
    {
        if(v != par){
            DFS2(v, u);
            sum[u] += sum[v];
            // m[{v, u}] = sum[u];
            // m[{u, v}] = sum[u];
        }
    }
    m[{u, par}] = sum[u];
    m[{par, u}] = sum[u];
}
int main(){
    int n, i;
    cin>>n;

    for(i=1;i<n;i++)
    {
        cin>>u[i]>>v[i];
        graph[u[i]].push_back(v[i]);
        graph[v[i]].push_back(u[i]);
    }

    DFS(1, 1);

    int k;
    cin>>k;
    for(i = 1; i <= k; i++){
        cin>>a[i]>>b[i];
        int lca = find_LCA(a[i], b[i]);
        if(lca == a[i]){
            sum[b[i]] ++;
            sum[a[i]] --;
        }
        else if(lca == b[i]){
            sum[a[i]] ++;
            sum[b[i]] --;
        }
        else
        {
            sum[a[i]] ++;
            sum[b[i]] ++;
            sum[lca] -= 2;
        }
    }

    DFS2(1, 0);

    for(i=1;i <= n-1; i++)
        cout<<m[{u[i], v[i]}]<<  ' ';
    cout<<endl;
    
    return 0;
}
/*
11
1 2
1 3
2 4
2 5
4 6
3 7
3 8
3 9
9 10
10 11

3
1 6
11 3
8 2
*/
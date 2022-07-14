#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 105

/** BPM using Kuhn's Algorithm ; Complexity - O(VE) **/
int Left[1005],Right[1005],vis[1005];
vector<int>  graph[1005];
bool Kuhn(int u)
{
    for(int i=0 ; i<(int)graph[u].size() ; i++){
        int v = graph[u][i];
        if(vis[v])continue;
        vis[v] = 1;
        if(Right[v]==-1 || Kuhn(Right[v])){
            Right[v] = u;
            Left[u] = v;
            return true;    ///Matching possible
        }
    }
    return false;   ///Matching not possible
}
int BPM(int setA)
{
    memset(Left , -1, sizeof(Left)); memset(Right , -1, sizeof(Right)); int m=setA;
    int cnt = 0;
    for(int i=1 ; i<=m ; i++){
        memset(vis , 0, sizeof(vis));
        if(Kuhn(i))
            cnt++;
    }
    return cnt;
}
int main()
{
    int i,j,k,u,v,n,e,bpm;
    scanf("%d %d",&n,&e);
    for(i=1 ; i<=e ; i++){
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bpm = BPM(5);/// 5 means size of setA
    cout<<bpm<<endl;
    return 0;
}

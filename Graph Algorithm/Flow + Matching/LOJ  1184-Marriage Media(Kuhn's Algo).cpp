#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 105

int n, m;
int height[sz],age[sz],maritalstatus[sz];

/** BPM using Kuhn's Algorithm ; Complexity - O(VE) **/
int Left[sz],Right[sz],vis[sz];
vector<int> graph[sz];
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
    memset(Left , -1,sizeof(Left)); memset(Right , -1, sizeof(Right)); int m=setA;
    int cnt = 0;
    for(int i=1 ; i<=m ; i++){
        memset(vis , 0, sizeof(vis));
        if(Kuhn(i))
            cnt++;
    }
    return cnt;
}

void Solve(int t)
{
    int source, destination, i, j, u, v, c, ans;

    cin>>m>>n;
    for(i=1;i<=m+n;i++)
    {
        cin>>height[i]>>age[i]>>maritalstatus[i];
    }

    for(i=1;i<=m;i++)
    {
        for(j=m+1;j<=m+n;j++)
        {
            if(abs(height[i]-height[j])<=12 && abs(age[i]-age[j])<=5 && maritalstatus[i]==maritalstatus[j])
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    ans = BPM(m);
    printf("Case %d: %d\n",t,ans);
    for(i=1;i<=m+n;i++)
        graph[i].clear();
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


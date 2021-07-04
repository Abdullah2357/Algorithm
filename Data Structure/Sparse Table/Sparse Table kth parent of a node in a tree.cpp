#include<bits/stdc++.h>
#define ll     long long
using namespace std;

vector<int> graph[100005];
int Parent[20][100005];

void Compute_ST(int u,int par)
{
    for(auto v:graph[u])
    {
        if(v==par)
        {
            continue;
        }
        int i=1;
        Parent[0][v] = u;
        while(i<=18)
        {
            Parent[i][v] = Parent[i-1][Parent[(i-1)][v]];
            i++;
        }
        Compute_ST(v, u);
    }
}
int main()
{
    int n,i,u,v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Compute_ST(1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int x,k,ans;
        cin>>x>>k;
        for(i=18;i>=0;i--)
        {
            if(k>=1<<i)
            {
                x = Parent[i][x];
                k-=1<<i;
            }
        }
        cout<<x<<endl;
    }
}

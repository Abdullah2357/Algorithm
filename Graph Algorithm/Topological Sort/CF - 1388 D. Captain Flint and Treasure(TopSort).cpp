#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 200005

ll n,a[sz],indeg[sz],b[sz],ans=0;
vector<int> graph[sz];
vector<int> pos,neg;

ll TopBFS(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans += a[u];
        if(a[u]>=0)
            pos.push_back(u);
        else
            neg.push_back(u);
        if(b[u]!=-1)
        {
            indeg[b[u]]--;
            if(indeg[b[u]]==0)
                q.push(b[u]);
            if(a[u]>=0)
                a[b[u]] += a[u];
        }
    }
}
int main()
{
    ll i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]!=-1){
            indeg[b[i]]++;
            graph[i].push_back(b[i]);
        }
    }
    TopBFS(n);
    cout<<ans<<endl;
    reverse(neg.begin(),neg.end());
    for(auto it:pos)
        cout<<it<< ' ';
    for(auto it:neg)
        cout<<it<< ' ';
    cout<<endl;
    return 0;
}


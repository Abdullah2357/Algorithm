#include<bits/stdc++.h>
using namespace std;

#define sz 10005

int indeg[sz],indeg2[sz];

vector<int> graph[sz];
vector<int> ans;

struct info
{
    int a;
    info(int _a)
    {
        a = _a;
    }
    bool operator < (const info&p) const
    {
        return a<p.a;
    }
};


void TopBFS(int n)
{
    priority_queue<info> pq;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0){
            pq.push(info(i));
        }
    }
    while(!pq.empty())
    {
        int u = pq.top().a;
        pq.pop();
        ans.push_back(u);
        for(auto v:graph[u])
        {
            indeg[v]--;
            if(indeg[v]==0){
                pq.push(info(v));

            }
        }
    }
}
void Clean(int n)
{
    ans.clear();
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        indeg[i] = 0;
    }
}
void Solve(int t)
{

    int u,v,i,n,m,j,fg=1,fg2=1;

    scanf("%d",&n);
    Clean(28);
    string s[105];
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<min(s[i].size(),s[i+1].size());j++)
        {
            if(s[i][j]!=s[i+1][j])
            {
                graph[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                indeg[s[i+1][j]-'a']++;
                fg2=1;
                break;
            }
            else
                fg2=0;
        }
        if(!fg2 && s[i].size()>s[i+1].size())
            fg=0;
    }
    TopBFS(26);
    if(!fg || ans.size()!=26)
    {
        cout<<"Impossible\n";
    }
    else
    {
        for(i=0;i<ans.size();i++)
            cout<<(char)(ans[i]+'a');
        cout<<endl;
    }
}
int main()
{
    int t,T=1;
    //scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

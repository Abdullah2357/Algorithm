#include<bits/stdc++.h>
using namespace std;

#define sz 10005

int indeg[sz];

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
    map<int,int> fre;


void TopBFS()
{
    priority_queue<info> pq;
    for(auto it:fre)
    {
        if(indeg[it.first]==0){
            pq.push(info(it.first));
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
    fre.clear();
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        indeg[i] = 0;
    }
}
void Solve(int t)
{

    int u,v,i,n=0,m,j,fg=1,fg2=1;

    Clean(28);
    string s[sz];
    for(i=1; ;i++)
    {
        cin>>s[i];
        if(s[i]=="#")
            break;
        n++;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<min(s[i].size(),s[i+1].size());j++)
        {
            if(s[i][j]!=s[i+1][j])
            {
                graph[s[i][j]-'A'].push_back(s[i+1][j]-'A');
                indeg[s[i+1][j]-'A']++;
                fg2=1;
                fre[s[i][j]-'A']++;
                fre[s[i+1][j]-'A']++;
                break;
            }
        }
    }
    TopBFS();
    for(i=0;i<ans.size();i++)
        cout<<(char)(ans[i]+'A');
    cout<<endl;
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


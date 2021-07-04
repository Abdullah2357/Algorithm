#include<bits/stdc++.h>
#define ll     long long
using namespace std;

#define sz 105

ll n;

struct info
{
    int t,d,p,id;
    info(int _t, int _d, int _p,int _id)
    {
        t = _t;
        d = _d;
        p = _p;
        id = _id;
    }
    bool operator < (const info &x) const
    {
        if(d!=x.d)
            return d<x.d;
        return t<x.t;
    }
};
ll dp[105][2005];
vector<info> a;
ll FuN(int pos,int time)
{
    if(pos>n || time>2000)
        return 0;
    if(dp[pos][time] != -1)
        return dp[pos][time];
    ll ret1 = 0,ret2 = 0;
    ret1 = FuN(pos+1,time);
    if(time+a[pos].t < a[pos].d)
        ret2 = a[pos].p + FuN(pos+1,time+a[pos].t);
    return dp[pos][time] = max(ret1,ret2);
}
vector<ll> v;
void Find(int pos,int time)
{
    if(pos>n || time>2000)
        return ;
    ll ret1 = 0,ret2 = 0;
    if(time+a[pos].t < a[pos].d){
        ret1 = FuN(pos+1,time);
        ret2 = a[pos].p + FuN(pos+1,time+a[pos].t);
        if(ret1>ret2)
        {
            Find(pos+1,time);
        }
        else
        {
            v.push_back(a[pos].id);
            Find(pos+1,time+a[pos].t);
        }
    }
    else
    {
        Find(pos+1,time);
    }
}
void Solve()
{
    ll i, j, fg = 0, x, y,z, ans = 0;
    cin>>n;
    a.push_back(info(0,0,0,0));
    for(i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        a.push_back(info(x,y,z,i));
//        cin>>a[i].t>>a[i].d>>a[i].p;
    }
    sort(a.begin(),a.end());
    memset(dp,-1,sizeof(dp));
    ans = FuN(1,0);
    Find(1,0);
    cout<<ans<<endl;
    cout<<v.size()<<endl;
    for(auto it:v)
        cout<<it<< ' ';
    cout<<endl;
}
int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve();
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 200005


ll n,a[sz],sum[sz];
vector<ll> tree[sz*4];

void  Init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].push_back(sum[b]);
        return ;
    }
    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    merge(tree[lft].begin(),tree[lft].end(),tree[rgt].begin(),tree[rgt].end(),back_inserter(tree[node]));

}

ll Query(ll node,ll b,ll e,ll i,ll j,ll v)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        ll lo = 0,hi = tree[node].size()-1,mid,res = 0;
        while(lo<=hi)
        {
            mid=  (lo+hi)/2;
            if(tree[node][mid]<v)
            {
                res = mid+1;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return res;
    }

    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = lft+1;

    ll p1 = Query(lft,b,mid,i,j,v);
    ll p2 = Query(rgt,mid+1,e,i,j,v);

    return p1+p2;
}


void Solve(ll t)
{
    ll v,i,ans=0;
    cin>>n>>v;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }
    Init(1,1,n);
    for(i=1;i<=n;i++)
    {
        ans += Query(1,1,n,i,n,v+sum[i-1]);
    }
    cout<<ans<<endl;
}

int main()
{
    int t,T=1;
//    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

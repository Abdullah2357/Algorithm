#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 200005


ll n,a[sz],sum[sz];
vector<ll> tree[sz*5];

void  Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].clear();
        tree[node].push_back(a[b]);
        return ;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node].clear();
    merge(tree[lft].begin(),tree[lft].end(),tree[rgt].begin(),tree[rgt].end(),back_inserter(tree[node]));

}

ll Query(int node,int b,int e,int i,int j,int v)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        ll lo= 0,hi= tree[node].size()-1,mid,res  =0;
        while(lo<=hi)
        {
            mid = (lo+hi)>>1;
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

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    ll p1 = Query(lft,b,mid,i,j,v);
    ll p2 = Query(rgt,mid+1,e,i,j,v);

    return p1+p2;
}

void Solve(int t)
{
    ll v,i,ans=0,q,x1,y1,x2,y2;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    Init(1,1,n);
    for(i=1;i<n;i++)
    {
        ans += Query(1,1,n,i+1,n,a[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    int t,T=1;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        Solve(t);
    }
    return 0;
}

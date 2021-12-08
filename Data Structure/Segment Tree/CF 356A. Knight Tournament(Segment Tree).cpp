#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 300005


ll n,a[sz],l[sz],r[sz],x[sz];
ll tree[sz*4],lazy[sz*4];

void push_down(ll node,ll b,ll e)
{
    tree[node] = lazy[node]*(e-b+1);

    if(b!=e)
    {
        lazy[node<<1] = lazy[node];
        lazy[(node<<1) + 1] = lazy[node];
    }
    lazy[node] = -1;
}

ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(lazy[node]!=-1)
        push_down(node,b,e);

    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];

    ll mid = (b+e)>>1;
    ll sum1 = Query(node<<1,b,mid,i,j);
    ll sum2 = Query((node<<1) + 1,mid+1,e,i,j);

    return sum1+sum2;
}

void Set(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(lazy[node]!=-1)
        push_down(node,b,e);


    if(i>e || j< b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node] = ((e-b+1)*x);
        if(b!=e)
        {
            lazy[node<<1] = x;
            lazy[(node<<1)+1] = x;
        }
        return;
    }

    ll mid = (b+e)>>1;

    Set(node<<1,b,mid,i,j,x);
    Set((node<<1)+1,mid+1,e,i,j,x);

    tree[node] = tree[node<<1]+tree[(node<<1)+1];
}

void Solve(int t)
{

    ll i,q,id,j,v;
    cin>>n>>q;

    for(i=1;i<=4*n;i++)
    {
        tree[i] = 0;
        lazy[i] = -1;
    }

    for(i=1;i<=q;i++)
    {
        cin>>l[i]>>r[i]>>x[i];
    }

    for(i=q;i>=1;i--)
    {
        Set(1,1,n,l[i],x[i]-1,x[i]);
        Set(1,1,n,x[i]+1,r[i],x[i]);
    }

    for(i=1;i<=n;i++)
    {
        cout<<Query(1,1,n,i,i)<< ' ';
    }
    cout<<endl;
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

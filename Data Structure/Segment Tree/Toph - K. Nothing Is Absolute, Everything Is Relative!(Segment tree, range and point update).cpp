#include<bits/stdc++.h>
#define ll      long long
using namespace std;


/**
Operation 1: L,R,X
    add X to sub-array[l,r]
Operation 2: L R
    Find the summation of absolute differences between the adjacent
    elements of the sub-array [L,R].
**/
#define sz 500005

ll n,a[sz],m;

ll tree[sz*6],lazy[sz*6],tree2[sz*6];

void Init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node] = a[b];
        tree2[node] = abs(a[b]-a[b-1]);
        return ;
    }
    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = lft+1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node] = tree[lft]+tree[rgt];
    tree2[node] = tree2[lft]+tree2[rgt];
}

void push_down(ll node,ll b,ll e)
{
    tree[node] = tree[node] + lazy[node]*(e-b+1);
    if(b!=e)
    {
        lazy[node<<1] += lazy[node];
        lazy[(node<<1)+1] += lazy[node];
    }
        lazy[node] = 0;
}

void Update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(lazy[node]!=0)
        push_down(node,b,e);

    if(i>e || j< b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node] += x*(e-b+1);
        if(b!=e)
        {
            lazy[node<<1] += x;
            lazy[(node<<1)+1]+=x;
        }
        return;
    }

    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = lft+1;

    Update(lft,b,mid,i,j,x);
    Update(rgt,mid+1,e,i,j,x);

    tree[node] = tree[lft] + tree[rgt];
}

void Update2(ll node,ll b,ll e,ll i,ll x)
{
    if(i>e || i< b)
        return ;
    if(b>=i && e<=i)
    {
        tree2[node] = x;
        return;
    }

    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = lft+1;

    Update2(lft,b,mid,i,x);
    Update2(rgt,mid+1,e,i,x);

    tree2[node] = tree2[lft] + tree2[rgt];
}


ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(lazy[node] != 0)
        push_down(node, b, e);
    if(i>e || j<b)
        return 0LL;


    if(b>=i && e<=j)
        return tree[node];

    ll mid = (b+e)>>1;
    ll sum1 = Query(node<<1,b,mid,i,j);
    ll sum2 = Query((node<<1)+1,mid+1,e,i,j);

    return sum1+sum2;
}
ll Query2(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return 0LL;


    if(b>=i && e<=j)
        return tree2[node];

    ll mid = (b+e)>>1;
    ll sum1 = Query2(node<<1,b,mid,i,j);
    ll sum2 = Query2((node<<1)+1,mid+1,e,i,j);

    return sum1+sum2;
}

void Solve(int t)
{
    ll i, j, x, y,ans = 0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    a[0] = 0;
    a[n+1] = 0;
    Init(1,1,n+1);
    while(m--)
    {
        ll id,l,r;
        cin>>id>>l>>r;
        if(id==1)
        {
            cin>>x;
            Update(1,1,n+1,l,r,x);
            ll p = Query(1,1,n+1,l,l);
            ll p2 = Query(1,1,n+1,l-1,l-1);
            ll q = Query(1,1,n+1,r,r);
            ll q2 = Query(1,1,n+1,r+1,r+1);
            Update2(1,1,n+1,l,abs(p-p2));
            Update2(1,1,n+1,r+1,abs(q-q2));
        }
        else
        {
            cout<<Query2(1,1,n+1,l+1,r)<<endl;
        }
    }
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

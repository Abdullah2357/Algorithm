#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define sz 100005


ll n,a[sz];
ll tree[sz*4],idx[sz*4];

void Init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = a[b];
        idx[node] = b;
        return ;
    }

    int lft = node<<1;
    int rgt = lft+1;
    int mid = (b+e)>>1;

    Init(lft,b,mid);
    Init(rgt,mid+1,e);

    tree[node] = max(tree[lft], tree[rgt]);
    if(tree[lft]>tree[rgt])
        idx[node] = idx[lft];
    else
        idx[node] = idx[rgt];
}


pair<ll,ll> Query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return {0,0};


    if(b>=i && e<=j)
        return make_pair(tree[node],idx[node]);

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    pair<ll,ll> p1 = Query(lft, b, mid, i, j);
    pair<ll,ll> p2 = Query(rgt, mid+1, e, i, j);

    if(p1.first>p2.first)
        return p1;
    return p2;
}

void Update(int node,int b,int e,int i,int x)
{
    if(i>e || i< b)
        return ;


    if(b>=i && e<=i)
    {
        tree[node] = x;
        idx[node] = i;
        return;
    }

    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = lft+1;

    Update(lft,b,mid,i,x);
    Update(rgt,mid+1,e,i,x);

    tree[node] = max( tree[lft], tree[rgt]);
    if(tree[lft] > tree[rgt])
        idx[node] = idx[lft];
    else
        idx[node]  = idx[rgt];
}

void Solve(int t)
{

    int i,q,id,j,v;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    Init(1,1,n);

    cin>>q;
    while(q--)
    {
        ll l,r,v;
        char ch;
        cin>>ch>>l>>r;
        if(ch=='Q')
        {
            pair<ll,ll> p1 = {0, 0}, p2 = {0, 0}, p3 = {0, 0};

            p1 = Query(1,1,n,l,r);
            if(p1.second-1>=l)
                p2 = Query(1,1,n,l,p1.second-1);
            if(p1.second+1<=r)
                p3 = Query(1,1,n,p1.second+1,r);

            cout<<p1.first + max(p2.first,p3.first)<<endl;
        }
        else
        {
            Update(1,1,n,l,r);
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
